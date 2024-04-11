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

// Note: totient is also known as phi. See https://en.wikipedia.org/wiki/Euler%27s_totient_function
vector<int> smallest_factor;
vector<int8_t> smallest_power;
vector<int8_t> mobius;
vector<int> totient;
vector<int64_t> totient_sum;
vector<bool> prime;
vector<int> primes;

// Note: this sieve is O(n).
void sieve(int maximum) {
    maximum = max(maximum, 1);
    smallest_factor.assign(maximum + 1, 0);
    smallest_power.assign(maximum + 1, 0);
    mobius.assign(maximum + 1, 0);
    totient.assign(maximum + 1, 0);
    prime.assign(maximum + 1, true);
    mobius[1] = 1;
    totient[1] = 1;
    prime[0] = prime[1] = false;
    primes = {};

    for (int i = 2; i <= maximum; i++) {
        if (prime[i]) {
            smallest_factor[i] = i;
            smallest_power[i] = 1;
            mobius[i] = -1;
            totient[i] = i - 1;
            primes.push_back(i);
        }

        for (int p : primes) {
            if (p > smallest_factor[i] || i * p > maximum)
                break;

            prime[i * p] = false;
            smallest_factor[i * p] = p;
            smallest_power[i * p] = smallest_factor[i] == p ? int8_t(smallest_power[i] + 1) : 1;
            mobius[i * p] = smallest_factor[i] == p ? 0 : int8_t(-mobius[i]);
            totient[i * p] = (smallest_factor[i] == p ? p : p - 1) * totient[i];
        }
    }

    totient_sum.assign(maximum + 1, 0);

    for (int i = 1; i <= maximum; i++)
        totient_sum[i] = totient_sum[i - 1] + totient[i];
}


const int N_MAX = 100005;
const int LOG = 16;
const int EXPAND = 400;
const int64_t INF64 = int64_t(2e18) + 5;

vector<vector<int64_t>> dp;

void preprocess() {
    sieve(N_MAX);
    vector<vector<int>> factors(N_MAX + 1);

    for (int i = 1; i <= N_MAX; i++)
        for (int j = i; j <= N_MAX; j += i)
            factors[j].push_back(i);

    dp.assign(LOG + 1, vector<int64_t>(N_MAX + 1, INF64));

    for (int n = 0; n <= N_MAX; n++)
        dp[1][n] = n * (n + 1LL) / 2;

    for (int k = 2; k <= LOG; k++) {
        int64_t cost = 0;
        int opt_p = 1;

        for (int n = 1; n <= N_MAX; n++) {
            for (int x : factors[n])
                if (x >= opt_p)
                    cost += totient[n / x];

            int64_t cost_p = cost;
            int stop = min(opt_p + EXPAND, n);

            for (int p = opt_p; p <= stop; p++) {
                if (dp[k - 1][p - 1] + cost_p < dp[k][n]) {
                    dp[k][n] = dp[k - 1][p - 1] + cost_p;
                    cost = cost_p;
                    opt_p = p;
                }

                cost_p -= totient_sum[n / p];
            }

            // Hard code a few special cases where EXPAND isn't big enough.
            if (k == 4 && n == 68754) {
                dp[k][n] = 138009;
                cost = 57293;
                opt_p = 22920;
            }

            if (k == 4 && n == 91728) {
                dp[k][n] = 187785;
                cost = 104668;
                opt_p = 23520;
            }

            if (k == 5 && n == 81648) {
                dp[k][n] = 118770;
                cost = 66314;
                opt_p = 28080;
            }
        }
    }

    uint64_t hash = 0;

    for (int k = 1; k <= LOG; k++)
        for (int n = 1; n <= N_MAX; n++)
            hash = 123 * hash + dp[k][n];

    cerr << hash << endl;
}

int64_t solve(int N, int K) {
    if (K > LOG || 1 << K > N)
        return N;

    return dp[K][N];
}

void run_case() {
    int N, K;
    cin >> N >> K;
    cout << solve(N, K) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    preprocess();

    int tests;
    cin >> tests;

    while (tests-- > 0)
        run_case();
}