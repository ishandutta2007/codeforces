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


int N;

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    cin >> N;

    if (N <= 2) {
        cout << -1 << '\n';
        return 0;
    }

    vector<vector<int>> board(N, vector<int>(N));

    const int THREE[3][3] = {
        {6, 8, 9},
        {2, 3, 4},
        {1, 7, 5}
    };

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = THREE[i][j];

    int current = 0;

    for (int dim = 4; dim <= N; dim++)
        if (dim % 2 == 0) {
            for (int i = 0; i < dim; i++)
                board[dim - 1][i] = current--;

            for (int i = dim - 2; i >= 0; i--)
                board[i][dim - 1] = current--;
        } else {
            for (int i = 0; i < dim; i++)
                board[i][dim - 1] = current--;

            for (int i = dim - 2; i >= 0; i--)
                board[dim - 1][i] = current--;
        }

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            board[i][j] += N * N - 9;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cout << board[i][j] << (j < N - 1 ? ' ' : '\n');
}