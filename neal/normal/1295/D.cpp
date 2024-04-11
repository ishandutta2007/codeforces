#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

long long totient(long long n) {
    long long result = n;

    for (long long p = 2; p * p <= n; p++)
        if (n % p == 0) {
            result = result / p * (p - 1);

            do {
                n /= p;
            } while (n % p == 0);
        }

    if (n > 1)
        result = result / n * (n - 1);

    return result;
}

void run_case() {
    long long A, M;
    cin >> A >> M;
    long long G = __gcd(A, M);
    A /= G;
    M /= G;
    cout << totient(M) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin >> tests;

    while (tests-- > 0)
        run_case();
}