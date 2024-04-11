#include <algorithm>
#include <array>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
using namespace std;

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }


template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef NEAL_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

vector<int> smallest_factor;
vector<bool> prime;
vector<int> primes;
vector<int8_t> unique_primes;

// Note: this sieve is O(n), but the constant factor is worse than the O(n log log n) sieve due to the multiplication.
void sieve(int maximum) {
    maximum = max(maximum, 1);
    smallest_factor.assign(maximum + 1, 0);
    prime.assign(maximum + 1, true);
    prime[0] = prime[1] = false;
    primes = {};

    for (int i = 2; i <= maximum; i += 2) {
        prime[i] = i == 2;
        smallest_factor[i] = 2;
    }

    for (int i = 3; i <= maximum; i += 2) {
        if (prime[i]) {
            smallest_factor[i] = i;
            primes.push_back(i);
        }

        for (int p : primes) {
            if (p > smallest_factor[i] || int64_t(i) * p > maximum)
                break;

            prime[i * p] = false;
            smallest_factor[i * p] = p;
        }
    }

    if (maximum >= 2)
        primes.insert(primes.begin(), 2);

    unique_primes.assign(maximum + 1, 0);

    for (int i = 2; i <= maximum; i++) {
        int p = smallest_factor[i];
        unique_primes[i] = unique_primes[i / p] + ((i / p) % p != 0);
    }
}

// Prime factorizes n in worst case O(sqrt n / log n). Requires having run `sieve` up to at least sqrt(n).
// If we've run `sieve` up to at least n, takes O(log n) time.
vector<pair<int64_t, int>> prime_factorize(int64_t n) {
    int64_t sieve_max = int64_t(smallest_factor.size()) - 1;
    assert(1 <= n && n <= sieve_max * sieve_max);
    vector<pair<int64_t, int>> result;

    if (n <= sieve_max) {
        while (n != 1) {
            int64_t p = smallest_factor[n];
            int exponent = 0;

            do {
                n /= p;
                exponent++;
            } while (n % p == 0);

            result.emplace_back(p, exponent);
        }

        return result;
    }

    for (int64_t p : primes) {
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

vector<int64_t> generate_factors(const vector<pair<int64_t, int>> &prime_factors, bool sorted = false) {
    // See http://oeis.org/A066150 and http://oeis.org/A036451 for upper bounds on number of factors.
    static vector<int64_t> buffer;
    int product = 1;

    for (auto &pf : prime_factors)
        product *= pf.second + 1;

    vector<int64_t> factors = {1};
    factors.reserve(product);

    if (sorted)
        buffer.resize(product);

    for (auto &pf : prime_factors) {
        int64_t p = pf.first;
        int exponent = pf.second;
        int before_size = int(factors.size());

        for (int i = 0; i < exponent * before_size; i++)
            factors.push_back(factors[factors.size() - before_size] * p);

        if (sorted && factors[before_size - 1] > p)
            for (int section = before_size; section < int(factors.size()); section *= 2)
                for (int i = 0; i + section < int(factors.size()); i += 2 * section) {
                    int length = min(2 * section, int(factors.size()) - i);
                    merge(factors.begin() + i, factors.begin() + i + section,
                          factors.begin() + i + section, factors.begin() + i + length,
                          buffer.begin());
                    copy(buffer.begin(), buffer.begin() + length, factors.begin() + i);
                }
    }

    assert(int(factors.size()) == product);
    return factors;
}


void run_case() {
    int64_t C, D, X;
    cin >> C >> D >> X;
    vector<pair<int64_t, int>> prime_factors = prime_factorize(X);
    vector<int64_t> factors = generate_factors(prime_factors);
    int64_t total = 0;

    for (int64_t g : factors) {
        int64_t ckd = X / g;
        int64_t ck = ckd + D;

        if (ck % C != 0)
            continue;

        int64_t k = ck / C;
        total += 1 << unique_primes[k];
    }

    cout << total << '\n';
}

const int X_MAX = int(2e7) + 5;

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    cerr << fixed << setprecision(3);

    long double begin = clock();
    sieve(X_MAX);
    cerr << (clock() - begin) / CLOCKS_PER_SEC << 's' << endl;

    int tests;
    cin >> tests;

    while (tests-- > 0)
        run_case();
}