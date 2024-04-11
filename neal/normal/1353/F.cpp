#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef NEAL_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif


const int64_t INF64 = int64_t(2e18) + 5;

void run_case() {
    int N, M;
    cin >> N >> M;
    vector<vector<int64_t>> A(N, vector<int64_t>(M));
    vector<int64_t> sorted;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            cin >> A[i][j];
            A[i][j] -= i + j;
            sorted.push_back(A[i][j]);
        }

    sort(sorted.begin(), sorted.end());
    int64_t best = INF64;

    for (int64_t minimum : sorted) {
        vector<vector<int64_t>> dp(N, vector<int64_t>(M, INF64));

        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                if (A[i][j] < minimum)
                    A[i][j] = INF64;

        dp[0][0] = A[0][0];

        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) {
                if (i > 0)
                    dp[i][j] = min(dp[i][j], dp[i - 1][j] + A[i][j]);

                if (j > 0)
                    dp[i][j] = min(dp[i][j], dp[i][j - 1] + A[i][j]);
            }

        if (dp[N - 1][M - 1] < INF64)
            best = min(best, dp[N - 1][M - 1] - minimum * (N + M - 1));
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