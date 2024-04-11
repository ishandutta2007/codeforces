#include <algorithm>
#include <array>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
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


const int INF = int(1e9) + 5;

void run_case() {
    int N, M;
    cin >> N >> M;
    vector<string> grid(N);

    for (auto &row : grid)
        cin >> row;

    vector<vector<int>> width(N, vector<int>(M, INF));

    for (int r = 0; r < N; r++) {
        int count = 0;

        for (int c = 0; c < M; c++) {
            count = grid[r][c] == '*' ? count + 1 : 0;
            width[r][c] = min(width[r][c], count);
        }

        count = 0;

        for (int c = M - 1; c >= 0; c--) {
            count = grid[r][c] == '*' ? count + 1 : 0;
            width[r][c] = min(width[r][c], count);
        }
    }

    int spruces = 0;

    for (int c = 0; c < M; c++) {
        int minimum = INF;

        for (int r = 0; r < N; r++) {
            minimum = min(minimum + 1, width[r][c]);
            int here = min(r + 1, minimum);
            spruces += here;
        }
    }

    cout << spruces << '\n';
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