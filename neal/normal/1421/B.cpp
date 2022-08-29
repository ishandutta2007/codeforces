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


void run_case() {
    int N;
    cin >> N;
    vector<string> grid(N);

    for (auto &row : grid)
        cin >> row;

    const vector<array<int, 2>> squares = {{0, 1}, {1, 0}, {N - 2, N - 1}, {N - 1, N - 2}};
    const string wanted[2] = {"0011", "1100"};

    for (string want : wanted) {
        int different = 0;

        for (int i = 0; i < 4; i++)
            different += grid[squares[i][0]][squares[i][1]] != want[i];

        if (different <= 2) {
            cout << different << '\n';

            for (int i = 0; i < 4; i++)
                if (grid[squares[i][0]][squares[i][1]] != want[i])
                    cout << squares[i][0] + 1 << ' ' << squares[i][1] + 1 << '\n';

            return;
        }
    }

    assert(false);
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