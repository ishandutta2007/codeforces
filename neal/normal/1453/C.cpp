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

template<typename T_vector>
void output_vector(const T_vector &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = int(v.size());

    for (int i = start; i < end; i++)
        cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');
}


const int D = 10;

void run_case() {
    int N;
    cin >> N;
    vector<string> board(N);

    for (auto &row : board)
        cin >> row;

    vector<int> answers(D, 0);

    for (int rotate = 0; rotate < 4; rotate++) {
        vector<int> highest(D, N);

        for (int row = 0; row < N; row++) {
            vector<int> first(D, N), last(D, -1);

            for (int i = 0; i < N; i++) {
                int c = board[row][i] - '0';
                highest[c] = min(highest[c], row);
                first[c] = min(first[c], i);
                last[c] = max(last[c], i);
            }

            for (int d = 0; d < D; d++) {
                if (first[d] >= N)
                    continue;

                answers[d] = max(answers[d], (last[d] - first[d]) * row);
                answers[d] = max(answers[d], (N - 1 - first[d]) * (row - highest[d]));
                answers[d] = max(answers[d], last[d] * (row - highest[d]));
            }
        }

        vector<string> next_board(N, string(N, '?'));

        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                next_board[i][j] = board[j][N - 1 - i];

        board.swap(next_board);
    }

    output_vector(answers);
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