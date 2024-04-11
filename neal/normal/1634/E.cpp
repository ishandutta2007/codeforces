#include <algorithm>
#include <array>
#include <bitset>
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

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }


template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

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

    int M;
    cin >> M;
    vector<vector<int>> A(M);
    vector<string> answers(M);
    int N = 0;

    for (int i = 0; i < M; i++) {
        int n;
        cin >> n;
        A[i].resize(n);
        N += n;
        answers[i].assign(n, 'L');

        for (auto &a : A[i])
            cin >> a;
    }

    map<int, int> freq;

    for (auto &arr : A)
        for (auto &a : arr)
            freq[a]++;

    for (auto &pr : freq)
        if (pr.second % 2 != 0) {
            cout << "NO" << '\n';
            return 0;
        }

    cout << "YES" << '\n';
    map<int, set<pair<int, int>>> neighbors;

    for (int i = 0; i < M; i++)
        for (int j = 0; j < int(A[i].size()); j++)
            neighbors[A[i][j]].emplace(i, j ^ 1);

    for (int i = 0; i < M; i++)
        for (int j = 0; j < int(A[i].size()); j += 2) {
            if (answers[i][j] == 'R' || answers[i][j ^ 1] == 'R')
                continue;

            int x = A[i][j], y = A[i][j ^ 1];
            answers[i][j] = 'R';
            neighbors[x].erase(make_pair(i, j ^ 1));
            neighbors[y].erase(make_pair(i, j));

            while (y != x) {
                pair<int, int> neigh = *neighbors[y].begin();
                int row = neigh.first;
                int col = neigh.second ^ 1;
                answers[row][col] = 'R';
                neighbors[A[row][col]].erase(make_pair(row, col ^ 1));
                neighbors[A[row][col ^ 1]].erase(make_pair(row, col));
                y = A[row][col ^ 1];
            }
        }

    for (auto &ans : answers)
        cout << ans << '\n';
}