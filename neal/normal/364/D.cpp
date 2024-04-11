#include <algorithm>
#include <cassert>
#include <chrono>
#include <iostream>
#include <random>
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

// http://oeis.org/A066150 and http://oeis.org/A036451
const int FACTORS_MAX = 185000;

long long factors[FACTORS_MAX];

int generate_factors(const vector<pair<long long, int>> &prime_factors, bool sorted = false) {
    static long long buffer[FACTORS_MAX];
    int f_size = 0;
    factors[f_size++] = 1;

    for (auto &pf : prime_factors) {
        long long p = pf.first;
        int exponent = pf.second;
        int before_size = f_size;

        for (int e = 1; e <= exponent; e++)
            for (int i = 0; i < before_size; i++) {
                factors[f_size] = factors[f_size - before_size] * p;
                f_size++;
            }

        if (sorted && factors[before_size - 1] > p)
            for (int section = before_size; section < f_size; section *= 2)
                for (int i = 0; i + section < f_size; i += 2 * section) {
                    int length = min(2 * section, f_size - i);
                    merge(factors + i, factors + i + section, factors + i + section, factors + i + length, buffer);
                    copy(buffer, buffer + length, factors + i);
                }
    }

    return f_size;
}

auto random_address = [] { char *p = new char; delete p; return (uint64_t) p; };
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count() * (random_address() | 1));

const int A_SQRT_MAX = 1e6 + 5;
const int ATTEMPTS = 12;

int N;
vector<long long> A;
long long best = 1;

void attempt(long long initial) {
    int f_size = generate_factors(prime_factorize(initial), true);
    vector<int> counts(f_size, 0);

    for (auto &a : A) {
        long long x = __gcd(a, initial);
        int position = lower_bound(factors, factors + f_size, x) - factors;
        counts[position]++;
    }

    for (int i = f_size - 1; i >= 0; i--)
        if (factors[i] > best) {
            int total = 0;

            for (int j = i; j < f_size; j++)
                if (factors[j] % factors[i] == 0)
                    total += counts[j];

            if (2 * total >= N)
                best = max(best, factors[i]);
        }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve(A_SQRT_MAX);

    cin >> N;
    A.resize(N);

    for (auto &a : A)
        cin >> a;

    shuffle(A.begin(), A.end(), rng);

    for (int i = 0; i < min(N, ATTEMPTS); i++)
        attempt(A[i]);

    cout << best << '\n';
}