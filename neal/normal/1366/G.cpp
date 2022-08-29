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
bool minimize(T1 &a, const T2 &b) {
    if (b < a) {
        a = b;
        return true;
    }

    return false;
}


const int NM_MAX = 10005;

int main() {
    string S, T;
    cin >> S >> T;
    int N = int(S.size());
    int M = int(T.size());

    vector<vector<int16_t>> dp(N + 1, vector<int16_t>(M + 1, NM_MAX));
    dp[0][0] = 0;

    for (int i = 0; i < N; i++) {
        // Delete this char.
        for (int j = 0; j <= M; j++)
            minimize(dp[i + 1][j], dp[i][j] + 1);

        // Keep this char.
        for (int j = 0; j < M; j++)
            if (S[i] == T[j])
                minimize(dp[i + 1][j + 1], dp[i][j]);

        // Pop this char. We can show that you can just greedily continue in the string until it's popped.
        if (S[i] != '.') {
            int until = -1;

            for (int x = i, count = 0; x < N; x++) {
                count += S[x] == '.' ? -1 : +1;

                if (count == 0) {
                    until = x + 1;
                    break;
                }
            }

            if (until >= 0) {
                for (int j = 0; j <= M; j++)
                    minimize(dp[until][j], dp[i][j]);
            }
        }
    }

    cout << dp[N][M] << '\n';
}