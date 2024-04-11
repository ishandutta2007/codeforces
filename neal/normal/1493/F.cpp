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


int main() {
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;
    sieve(N + M);
    int orig_N = N, orig_M = M;

    auto query = [&](int h, int w, int i1, int j1, int i2, int j2) -> bool {
        cout << "? " << h << ' ' << w << ' ' << i1 + 1 << ' ' << j1 + 1 << ' ' << i2 + 1 << ' ' << j2 + 1 << endl;
        int result;
        cin >> result;
        return result;
    };

    auto test_N = [&](int p) -> bool {
        int good = 1;

        while (2 * good < p) {
            if (!query(N / p * good, M, 0, 0, N / p * good, 0))
                return false;

            good *= 2;
        }

        int remain = N / p * (p - good);
        return query(remain, M, 0, 0, N - remain, 0);
    };

    for (int p = 1; p <= N; p++)
        while (prime[p] && N % p == 0 && test_N(p))
            N /= p;

    auto test_M = [&](int p) -> bool {
        int good = 1;

        while (2 * good < p) {
            if (!query(N, M / p * good, 0, 0, 0, M / p * good))
                return false;

            good *= 2;
        }

        int remain = M / p * (p - good);
        return query(N, remain, 0, 0, 0, M - remain);
    };

    for (int p = 1; p <= M; p++)
        while (prime[p] && M % p == 0 && test_M(p))
            M /= p;

    dbg(N, M);

    auto count_factors = [&](int n) {
        int count = 0;

        for (int i = 1; i <= n; i++)
            count += n % i == 0;

        return count;
    };

    cout << "! " << count_factors(orig_N / N) * count_factors(orig_M / M) << endl;
}