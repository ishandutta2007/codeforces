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

    int N;
    cin >> N;
    vector<vector<int64_t>> A(N, vector<int64_t>(N));

    for (int r = 0; r < N; r++)
        for (int c = 0; c < N; c++)
            A[r][c] = (r & 1LL) << (r + c);

    for (int r = 0; r < N; r++)
        for (int c = 0; c < N; c++)
            cout << A[r][c] << (c < N - 1 ? ' ' : '\n');

    cout << flush;
    int Q;
    cin >> Q;

    for (int q = 0; q < Q; q++) {
        int64_t k;
        cin >> k;
        int row = N - 1, col = N - 1;
        vector<array<int, 2>> path = {{row, col}};

        while (row > 0 || col > 0) {
            if (row > 0 && (k >> (row - 1 + col) & 1) == ((row - 1) & 1))
                row--;
            else
                col--;

            path.push_back({row, col});
        }

        reverse(path.begin(), path.end());

        for (auto &xy : path)
            cout << xy[0] + 1 << ' ' << xy[1] + 1 << '\n';

        cout << flush;
    }
}