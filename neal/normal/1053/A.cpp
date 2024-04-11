#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

long long N, M, K;

vector<long long> compute_factors(long long n) {
    vector<long long> factors;

    for (long long i = 1; i * i <= n; i++)
        if (n % i == 0) {
            factors.push_back(i);

            if (i * i < n)
                factors.push_back(n / i);
        }

    return factors;
}

int main() {
    cin >> N >> M >> K;

    if (2 * N * M % K != 0) {
        cout << "NO" << endl;
        return 0;
    }

    long long area = 2 * N * M / K;
    vector<long long> n_factors = compute_factors(2 * N);
    vector<long long> m_factors = compute_factors(2 * M);

    for (long long base : n_factors)
        for (long long height : m_factors)
            if (base <= N && height <= M && base * height == area) {
                cout << "YES" << endl;
                cout << "0 0" << endl;
                cout << base << ' ' << 0 << endl;
                cout << 0 << ' ' << height << endl;
                return 0;
            }

    assert(false);
}