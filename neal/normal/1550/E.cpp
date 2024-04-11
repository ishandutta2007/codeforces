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


const int INF = int(1e9) + 5;

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N, K;
    string S;
    cin >> N >> K >> S;

    auto possible = [&](int len) -> bool {
        vector<vector<int>> earliest(K, vector<int>(N + 1, INF));

        for (int c = 0; c < K; c++) {
            int last = N;

            for (int i = N - 1; i >= 0; i--) {
                if (S[i] != '?' && S[i] != 'a' + c)
                    last = i;

                earliest[c][i] = earliest[c][i + 1];

                if (last >= i + len)
                    earliest[c][i] = i;
            }
        }

        vector<int> dp(1 << K, INF);
        dp[0] = 0;

        for (int mask = 0; mask < 1 << K; mask++) {
            if (dp[mask] >= N)
                continue;

            for (int a = 0; a < K; a++)
                if ((mask >> a & 1) == 0)
                    dp[mask | 1 << a] = min(dp[mask | 1 << a], earliest[a][dp[mask]] + len);
        }

        return dp[(1 << K) - 1] <= N;
    };

    int low = 0, high = N / K;

    while (low < high) {
        int mid = low + (high - low + 1) / 2;

        if (possible(mid))
            low = mid;
        else
            high = mid - 1;
    }

    cout << low << '\n';
}