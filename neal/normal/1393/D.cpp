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

vector<int> calc_left(int n, const string &row, const vector<int> &vertical) {
    vector<int> left(n);
    int minimum = INF, change = -1;

    for (int i = 0; i < n; i++) {
        if (i == 0 || row[i] != row[i - 1])
            change = i - 1;

        minimum = min(minimum + 1, vertical[i]);
        left[i] = min(minimum, i - change);
    }

    return left;
}

int solve(int n, string row, vector<int> vertical) {
    vector<int> left = calc_left(n, row, vertical);

    reverse(row.begin(), row.end());
    reverse(vertical.begin(), vertical.end());

    vector<int> right = calc_left(n, row, vertical);
    reverse(right.begin(), right.end());
    int sum = 0;

    for (int i = 0; i < n; i++)
        sum += min(left[i], right[i]);

    return sum;
}

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N, M;
    cin >> N >> M;
    vector<string> grid(N);

    for (string &row : grid)
        cin >> row;

    vector<vector<int16_t>> up(N, vector<int16_t>(M, 1));
    vector<vector<int16_t>> down(N, vector<int16_t>(M, 1));

    for (int r = 1; r < N; r++)
        for (int c = 0; c < M; c++)
            if (grid[r][c] == grid[r - 1][c])
                up[r][c] = up[r - 1][c] + 1;

    for (int r = N - 2; r >= 0; r--)
        for (int c = 0; c < M; c++)
            if (grid[r][c] == grid[r + 1][c])
                down[r][c] = down[r + 1][c] + 1;

    int total = 0;

    for (int r = 0; r < N; r++) {
        vector<int> vertical(M);

        for (int c = 0; c < M; c++)
            vertical[c] = min(up[r][c], down[r][c]);

        total += solve(M, grid[r], vertical);
    }

    cout << total << '\n';
}