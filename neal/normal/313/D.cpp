#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
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


const int64_t INF64 = int64_t(2e18) + 5;

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N, M, K;
    cin >> N >> M >> K;
    vector<vector<pair<int, int>>> choices(N + 1);

    for (int i = 0; i < M; i++) {
        int L, R, C;
        cin >> L >> R >> C;
        L--;
        choices[R].emplace_back(L, C);
    }

    vector<vector<int64_t>> dp(N + 1, vector<int64_t>(N + 1, INF64));
    dp[0][0] = 0;

    for (int end = 1; end <= N; end++) {
        for (int k = 0; k <= N; k++)
            dp[end][k] = min(dp[end][k], dp[end - 1][k]);

        vector<int64_t> cheapest(N + 1, INF64);

        for (auto &choice : choices[end]) {
            int L = choice.first;
            int C = choice.second;
            cheapest[L] = min<int64_t>(cheapest[L], C);
        }

        for (int x = 0; x < N; x++)
            cheapest[x + 1] = min(cheapest[x + 1], cheapest[x]);

        for (int left = 0; left < end; left++)
            for (int k = 0; k <= left; k++)
                dp[end][k + (end - left)] = min(dp[end][k + (end - left)], dp[left][k] + cheapest[left]);

        for (int k = N - 1; k >= 0; k--)
            dp[end][k] = min(dp[end][k], dp[end][k + 1]);
    }

    cout << (dp[N][K] < INF64 ? dp[N][K] : -1) << '\n';
}