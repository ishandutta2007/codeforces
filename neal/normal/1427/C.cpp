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


const int INF = 1e9 + 5;

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int R, N;
    cin >> R >> N;
    vector<int> X(N + 1), Y(N + 1), T(N + 1);
    X[0] = Y[0] = 1;
    T[0] = 0;

    for (int i = 1; i <= N; i++)
        cin >> T[i] >> X[i] >> Y[i];

    vector<int> dp(N + 1, -INF);
    dp[0] = 0;

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j <= min(N, i + 2 * R); j++) {
            int d = abs(X[i] - X[j]) + abs(Y[i] - Y[j]);

            if (d <= T[j] - T[i])
                dp[j] = max(dp[j], dp[i] + 1);
        }

        for (int j = i + 2 * R; j <= min(N, i + 4 * R); j++)
            dp[j] = max(dp[j], dp[i] + 1);
    }

    cout << *max_element(dp.begin(), dp.end()) << '\n';
}