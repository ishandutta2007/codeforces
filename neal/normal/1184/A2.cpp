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

int N;
string S;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> S;
    long long answer = 0;

    for (int d = 1; d <= N; d++)
        if (N % d == 0) {
            bool good = true;

            for (int start = 0; start < d; start++) {
                int sum = 0;

                for (int i = start; i < N; i += d)
                    sum ^= S[i] - '0';

                if (sum != 0) {
                    good = false;
                    break;
                }
            }

            if (good)
                answer += totient(N / d);
        }

    cout << answer << '\n';
}