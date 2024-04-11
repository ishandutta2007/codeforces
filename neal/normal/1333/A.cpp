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


void run_case() {
    int N, M;
    cin >> N >> M;
    vector<string> grid(N, string(M, '.'));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            grid[i][j] = "BW"[(i + j) % 2];

    if ((N * M) % 2 == 0) {
        bool found = false;

        for (int i = 0; i < N && !found; i += N - 1)
            for (int j = 0; j < M && !found; j += M - 1)
                if (grid[i][j] == 'W') {
                    grid[i][j] = 'B';
                    found = true;
                    break;
                }
    }

    for (string &row : grid)
        cout << row << '\n';
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