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

template<typename T, bool maximum_mode = false>
struct RMQ {
    static int highest_bit(int x) {
        return x == 0 ? -1 : 31 - __builtin_clz(x);
    }

    int n = 0;
    vector<T> values;
    vector<vector<int>> range_low;

    RMQ(const vector<T> &_values = {}) {
        if (!_values.empty())
            build(_values);
    }

    // Note: when `values[a] == values[b]`, returns b.
    int better_index(int a, int b) const {
        return (maximum_mode ? values[b] < values[a] : values[a] < values[b]) ? a : b;
    }

    void build(const vector<T> &_values) {
        values = _values;
        n = int(values.size());
        int levels = highest_bit(n) + 1;
        range_low.resize(levels);

        for (int k = 0; k < levels; k++)
            range_low[k].resize(n - (1 << k) + 1);

        for (int i = 0; i < n; i++)
            range_low[0][i] = i;

        for (int k = 1; k < levels; k++)
            for (int i = 0; i <= n - (1 << k); i++)
                range_low[k][i] = better_index(range_low[k - 1][i], range_low[k - 1][i + (1 << (k - 1))]);
    }

    // Note: breaks ties by choosing the largest index.
    int query_index(int a, int b) const {
        assert(0 <= a && a < b && b <= n);
        int level = highest_bit(b - a);
        return better_index(range_low[level][a], range_low[level][b - (1 << level)]);
    }

    T query_value(int a, int b) const {
        return values[query_index(a, b)];
    }
};


const int K_MAX = 30;

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);

    for (auto &a : A)
        cin >> a;

    vector<int> reach(N);

    for (int i = 0; i < N; i++)
        reach[i] = min(i + A[i], N - 1);

    RMQ<int, true> rmq(reach);
    int LOG = rmq.highest_bit(N);
    vector<vector<vector<uint16_t>>> dp(LOG + 1, vector<vector<uint16_t>>(N, vector<uint16_t>(K_MAX + 1, 0)));
    // dp[p][i][k] = the farthest we can get to starting from i using 2^p hops and k walks.

    for (int i = 0; i < N; i++)
        for (int k = 0; k <= K_MAX; k++)
            dp[0][i][k] = uint16_t(min(reach[i] + k, N - 1));

    for (int p = 1; p <= LOG; p++)
        for (int i = 0; i < N; i++)
            for (int k = 0; k <= K_MAX; k++) {
                // Find the largest x + A[x] we can get to.
                int best_reach = rmq.query_index(i, dp[p - 1][i][k] + 1);

                for (int add = 0; k + add <= K_MAX; add++)
                    dp[p][i][k + add] = max(dp[p][i][k + add], dp[p - 1][best_reach][add]);
            }

    auto query = [&](int L, int R, int K) -> int {
        if (L >= R)
            return 0;

        vector<int> farthest(K + 1, L);
        int moves = 0;

        for (int p = LOG; p >= 0; p--) {
            vector<int> nfarthest(K + 1, L);

            for (int k = 0; k <= K; k++)
                for (int add = 0; k + add <= K; add++)
                    nfarthest[k + add] = max(nfarthest[k + add], int(dp[p][farthest[k]][add]));

            // If we can get to R, don't include p.
            if (nfarthest[K] >= R)
                continue;

            moves += 1 << p;

            // Otherwise, find the largest x + A[x] we can get to for every value of k.
            for (int k = 0; k <= K; k++)
                farthest[k] = rmq.query_index(L, nfarthest[k] + 1);
        }

        return moves + 1;
    };

    for (int q = 0; q < Q; q++) {
        int L, R, K;
        cin >> L >> R >> K;
        L--; R--;
        cout << query(L, R, K) << '\n';
    }
}