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


int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N, M, Q;
    cin >> N >> M >> Q;
    array<string, 2> columns, rows;
    cin >> columns[0] >> columns[1] >> rows[0] >> rows[1];
    int best = N + M;

    for (int flip = 0; flip < 2; flip++) {
        array<int, 2> dp = {0, 0};

        // Cut individually to make the top row all blue or all red.
        for (char ch : rows[0])
            dp[ch == 'B']++;

        for (int i = 0; i < N; i++) {
            // We have the option of cutting all M vertical edges in this row.
            dp[0] = min(dp[0], dp[1] + M);
            dp[1] = min(dp[1], dp[0] + M);

            // Cut individually to make our current state all blue or all red.
            dp[columns[0][i] == 'B']++;
            dp[columns[1][i] == 'B']++;
        }

        // Cut the bottom row individually to make sure we end all blue or all red.
        for (char ch : rows[1])
            dp[ch == 'B']++;

        best = min({best, dp[0], dp[1]});
        swap(N, M);
        swap(rows, columns);
    }

    cout << best << '\n';
}