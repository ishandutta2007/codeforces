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

void run_case() {
    int N;
    cin >> N;
    vector<int> A(N);

    for (auto &a : A)
        cin >> a;

    vector<vector<bool>> clearable(N + 1, vector<bool>(N + 1, false));

    for (int i = 0; i <= N; i++) {
        vector<int> freq(N + 1, 0);
        int maximum = 0;

        for (int j = i; j <= N; j++) {
            clearable[i][j] = (j - i) % 2 == 0 && 2 * maximum <= j - i;

            if (j < N)
                maximum = max(maximum, ++freq[A[j]]);
        }
    }

    int best = 0;

    for (int x = 1; x <= N; x++) {
        vector<int> locations;

        for (int i = 0; i < N; i++)
            if (A[i] == x)
                locations.push_back(i);

        locations.push_back(N);
        int L = int(locations.size());

        vector<int> dp(L, -INF);
        dp[L - 1] = 0;

        for (int a = L - 1; a >= 0; a--)
            for (int b = a + 1; b < L; b++) {
                if (clearable[locations[a]][locations[b]])
                    dp[a] = max(dp[a], dp[b]);

                if (clearable[locations[a] + 1][locations[b]])
                    dp[a] = max(dp[a], 1 + dp[b]);
            }

        for (int a = 0; a < L; a++)
            if (clearable[0][locations[a]])
                best = max(best, dp[a]);
    }

    cout << best << '\n';
}

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int tests;
    cin >> tests;

    while (tests-- > 0)
        run_case();
}