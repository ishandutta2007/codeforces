#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename T, size_t size> ostream& operator<<(ostream &os, const array<T, size> &arr) { os << '{'; string sep; for (const auto &x : arr) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef NEAL_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

template<typename T1, typename T2>
bool maximize(T1 &a, const T2 &b) {
    if (a < T1(b)) {
        a = T1(b);
        return true;
    }

    return false;
}


const int INF = 1e9 + 5;

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N, M, K;
    cin >> N >> M >> K;
    int H = M / 2;
    vector<int> dp(K, -INF);
    dp[0] = 0;

    while (N-- > 0) {
        vector<int> A(M);

        for (auto &a : A)
            cin >> a;

        vector<vector<int>> row_dp(H + 1, vector<int>(K, -INF));
        row_dp[0][0] = 0;

        for (auto &a : A)
            for (int h = H - 1; h >= 0; h--)
                for (int x = 0; x < K; x++)
                    maximize(row_dp[h + 1][(x + a) % K], row_dp[h][x] + a);

        vector<int> next_dp(K, -INF);

        for (int x = 0; x < K; x++)
            for (int h = 0; h <= H; h++)
                for (int y = 0; y < K; y++)
                    maximize(next_dp[(x + y) % K], dp[x] + row_dp[h][y]);

        dp = next_dp;
    }

    cout << dp[0] << '\n';
}