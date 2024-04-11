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
    if (a < b) {
        a = b;
        return true;
    }

    return false;
}


const int INF = 1e9 + 5;

int main() {
    int N, K;
    string S, T;
    cin >> N >> K >> S >> T;
    vector<vector<int>> dp(N + 1, vector<int>(N + 1, -INF));
    dp[0][0] = 0;

    for (int i = 0; i < N; i++)
        for (int change = min(i, K); change >= 0; change--)
            for (int a = i; a >= 0; a--) {
                // Change to a
                maximize(dp[change + 1][a + 1], dp[change][a] + (T[0] == T[1] ? a : 0));

                // Change to b
                maximize(dp[change + 1][a], dp[change][a] + a);

                // Keep it the same
                maximize(dp[change][a + (S[i] == T[0])], dp[change][a] + (S[i] == T[1] ? a : 0));
            }

    int best = 0;

    for (int change = 0; change <= K; change++)
        maximize(best, *max_element(dp[change].begin(), dp[change].end()));

    cout << best << '\n';
}