#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <set>
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
    int N, M;
    cin >> N >> M;
    vector<vector<int64_t>> A(N, vector<int64_t>(M));

    for (auto &row : A)
        for (auto &a : row)
            cin >> a;

    int64_t total = 0;

    for (int i = 0; i < (N + 1) / 2; i++)
        for (int j = 0; j < (M + 1) / 2; j++) {
            int oi = N - 1 - i;
            int oj = M - 1 - j;
            set<pair<int, int>> coords;
            coords.emplace(i, j);
            coords.emplace(i, oj);
            coords.emplace(oi, j);
            coords.emplace(oi, oj);
            vector<int64_t> values;

            for (auto &pr : coords)
                values.push_back(A[pr.first][pr.second]);

            sort(values.begin(), values.end());
            int64_t median = values[values.size() / 2];

            for (auto &x : values)
                total += abs(x - median);
        }

    cout << total << '\n';
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