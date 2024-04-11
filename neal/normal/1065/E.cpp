#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const int MOD = 998244353;
const int INV2 = (MOD + 1) / 2;

long long mod_pow(long long a, long long p, long long m = MOD) {
    long long result = 1;

    while (p > 0) {
        if (p & 1)
            result = result * a % m;

        a = a * a % m;
        p >>= 1;
    }

    return result;
}

int N, M;
long long A;

int main() {
    scanf("%d %d %lld", &N, &M, &A);
    int b, prev = 0;
    long long answer = 1;

    for (int i = 0; i < M; i++) {
        scanf("%d", &b);
        int diff = b - prev;
        answer = answer * (mod_pow(A, 2 * diff) + mod_pow(A, diff)) % MOD * INV2 % MOD;
        prev = b;
    }

    answer = answer * mod_pow(A, N - 2 * b) % MOD;
    printf("%lld\n", answer);
}