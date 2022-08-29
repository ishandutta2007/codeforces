#include <algorithm>
#include <array>
#include <bitset>
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

unsigned mod_pow(unsigned a, unsigned b, unsigned mod) {
    unsigned result = 1;

    while (b > 0) {
        if (b & 1)
            result = unsigned(uint64_t(result) * a % mod);

        a = unsigned(uint64_t(a) * a % mod);
        b >>= 1;
    }

    return result;
}

bool miller_rabin(unsigned n) {
    if (n < 2)
        return false;

    // Check small primes.
    for (unsigned p : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29})
        if (n % p == 0)
            return n == p;

    int r = __builtin_ctz(n - 1);
    unsigned d = (n - 1) >> r;

    // https://en.wikipedia.org/wiki/Miller%E2%80%93Rabin_primality_test#Testing_against_small_sets_of_bases
    for (unsigned a : {2, 7, 61}) {
        unsigned x = mod_pow(a % n, d, n);

        if (x <= 1 || x == n - 1)
            continue;

        for (int i = 0; i < r - 1 && x != n - 1; i++)
            x = unsigned(uint64_t(x) * x % n);

        if (x != n - 1)
            return false;
    }

    return true;
}

vector<int> smallest_factor;
vector<bool> prime;
vector<int> primes;

void sieve(int maximum) {
    maximum = max(maximum, 1);
    smallest_factor.assign(maximum + 1, 0);
    prime.assign(maximum + 1, true);
    prime[0] = prime[1] = false;
    primes = {};

    for (int p = 2; p <= maximum; p++)
        if (prime[p]) {
            smallest_factor[p] = p;
            primes.push_back(p);

            for (int64_t i = int64_t(p) * p; i <= maximum; i += p)
                if (prime[i]) {
                    prime[i] = false;
                    smallest_factor[i] = p;
                }
        }
}


int get_exponent_sum(int n) {
    int sum = 0;

    for (int p : primes) {
        if (p * p * p > n)
            break;

        while (n % p == 0) {
            n /= p;
            sum++;
        }
    }

    if (n > 1)
        sum += miller_rabin(n) ? 1 : 2;

    return sum;
}

bool solve(int A, int B, int K) {
    if (A == B && K == 1)
        return false;

    int minimum = (A % B != 0) + (B % A != 0);

    if (K < minimum)
        return false;

    return get_exponent_sum(A) + get_exponent_sum(B) >= K;
}

void run_case() {
    int A, B, K;
    cin >> A >> B >> K;
    cout << (solve(A, B, K) ? "YES" : "NO") << '\n';
}

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    sieve(1000);

    int tests;
    cin >> tests;

    while (tests-- > 0)
        run_case();
}