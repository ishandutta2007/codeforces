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

    vector<vector<int>> dp(N + 1, vector<int>(N + 1, INF));
    dp[N - 1][N] = 0;

    for (int start = N - 2; start >= 0; start--) {
        if (A[start] == 0)
            continue;

        vector<int> subtract(N + 1, 0);
        int reach = start + A[start];
        assert(reach <= N - 1);
        int cost = 0;

        for (int jump = start + 1; jump <= reach; jump++) {
            if (dp[jump][reach + 1] < INF)
                dp[start][jump] = min(dp[start][jump], cost + dp[jump][reach + 1]);

            cost++;
            subtract[jump + A[jump]]++;
            cost -= subtract[jump];
        }

        for (int end = N - 1; end > start; end--)
            dp[start][end] = min(dp[start][end], dp[start][end + 1]);
    }

    cout << dp[0][1] << '\n';
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