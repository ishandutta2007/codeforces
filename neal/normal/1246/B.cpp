#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

vector<int> smallest_factor;
vector<bool> prime;
vector<int> primes;

void sieve(int maximum) {
    maximum = max(maximum, 2);
    smallest_factor.assign(maximum + 1, 0);
    prime.assign(maximum + 1, true);
    prime[0] = prime[1] = false;
    primes = {};

    for (long long p = 2; p <= maximum; p++)
        if (prime[p]) {
            smallest_factor[p] = p;
            primes.push_back(p);

            for (long long i = p * p; i <= maximum; i += p)
                if (prime[i]) {
                    prime[i] = false;
                    smallest_factor[i] = p;
                }
        }
}

// Prime factorizes n in worst case O(sqrt n / log n). Requires having run `sieve` up to at least sqrt(n).
// If we've run `sieve` up to at least n, takes O(log n) time.
vector<pair<long long, int>> prime_factorize(long long n) {
    assert(1 <= n && n <= (long long) smallest_factor.size() * (long long) smallest_factor.size());
    vector<pair<long long, int>> result;

    if (n < (int) smallest_factor.size()) {
        while (n != 1) {
            long long p = smallest_factor[n];
            int exponent = 0;

            do {
                n /= p;
                exponent++;
            } while (n % p == 0);

            result.emplace_back(p, exponent);
        }

        return result;
    }

    for (long long p : primes) {
        if (p * p > n)
            break;

        if (n % p == 0) {
            result.emplace_back(p, 0);

            do {
                n /= p;
                result.back().second++;
            } while (n % p == 0);
        }
    }

    if (n > 1)
        result.emplace_back(n, 1);

    return result;
}


const int A_MAX = 1e5 + 5;

int N, K;
vector<int> A;

vector<pair<long long, int>> clean_factors(vector<pair<long long, int>> &prime_factors) {
    vector<pair<long long, int>> new_factors;

    for (auto &pf : prime_factors) {
        pf.second %= K;

        if (pf.second != 0)
            new_factors.push_back(pf);
    }

    return new_factors;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve(A_MAX);
    cin >> N >> K;
    A.resize(N);

    for (int &a : A)
        cin >> a;

    map<vector<pair<long long, int>>, int> occur;
    long long total = 0;

    for (int i = 0; i < N; i++) {
        vector<pair<long long, int>> prime_factors = prime_factorize(A[i]);
        prime_factors = clean_factors(prime_factors);

        vector<pair<long long, int>> opposite = prime_factors;

        for (auto &pf : opposite)
            pf.second = (K - pf.second) % K;

        opposite = clean_factors(opposite);
        total += occur[opposite];
        occur[prime_factors]++;
    }

    cout << total << '\n';
}