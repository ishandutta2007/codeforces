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
const int ALPHABET = 26;
const char MIN_CHAR = 'a';

string sorted(string str) {
    sort(str.begin(), str.end());
    return str;
}

void run_case() {
    int N;
    string S, T;
    cin >> N >> S >> T;

    if (sorted(S) != sorted(T)) {
        cout << -1 << '\n';
        return;
    }

    // dp[x][y] = the minimum number of operations to transform the first `x` characters of S into a subsequence of the
    // first `y` characters of T.
    vector<int> dp(N + 1, 0);
    vector<int> S_freq(ALPHABET, 0);

    for (int i = 0; i < N; i++) {
        vector<int> next_dp(N + 1, INF);
        int minimum = INF;
        int goal_ch = S[i] - MIN_CHAR;
        S_freq[goal_ch]++;
        vector<int> T_freq(ALPHABET, 0);

        for (int j = 0; j < N; j++) {
            if (S[i] == T[j])
                minimum = min(minimum, dp[j]);

            next_dp[j + 1] = minimum;
            T_freq[T[j] - MIN_CHAR]++;

            if (T_freq[goal_ch] >= S_freq[goal_ch])
                next_dp[j + 1] = min(next_dp[j + 1], dp[j + 1] + 1);
        }

        swap(dp, next_dp);
    }

    cout << dp[N] << '\n';
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