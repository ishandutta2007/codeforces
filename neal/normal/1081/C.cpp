#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const long long MOD = 998244353;

long long mod_inv(long long a, long long m = MOD) {
    return a == 1 ? 1 : m - mod_inv(m % a, a) * m / a;
}

long long N, M, K;

long long choose(long long n, long long r) {
    long long product = 1;

    for (long long i = 0; i < r; i++)
        product = product * (n - i) % MOD * mod_inv(i + 1) % MOD;

    return product;
}

int main() {
    cin >> N >> M >> K;
    long long result = choose(N - 1, K) * M % MOD;

    for (int i = 0; i < K; i++)
        result = result * (M - 1) % MOD;

    cout << result << '\n';
}