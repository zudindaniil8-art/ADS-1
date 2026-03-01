// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"

bool checkPrime(uint64_t value) {
    if (value <= 1) return false;
    if (value == 2 || value == 3) return true;
    if (value % 2 == 0 || value % 3 == 0) return false;
    for (uint64_t i = 5; i * i <= value; i = i + 6) {
        if (value % i == 0 || value % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}
uint64_t nPrime(uint64_t n) {
    if (n == 0) return 0;
    uint64_t cnt = 0;
    uint64_t num = 2;
    while (true) {
        if (checkPrime(num)) {
            cnt++;
            if (cnt == n) {
                return num;
            }
        }
        num++;
    }
}
uint64_t nextPrime(uint64_t value) {
    if (value < 2) return 2;
    uint64_t start = value + 1;
    if (start % 2 == 0) {
        start++;
    }
    while (!checkPrime(start)) {
        start += 2;
    }
    return start;
}
uint64_t sumPrime(uint64_t hbound) {
    if (hbound <= 2) return 0;
    uint64_t total = 0;
    for (uint64_t j = 2; j < hbound; ++j) {
        if (checkPrime(j)) {
            total += j;
        }
    }
    return total;
}
uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
    if (hbound <= lbound + 2) return 0;
    uint64_t twins = 0;
    for (uint64_t k = lbound; k + 2 < hbound; ++k) {
        if (checkPrime(k) && checkPrime(k + 2)) {
            twins++;
        }
    }
    return twins;
}
