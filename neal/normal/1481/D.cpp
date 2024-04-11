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


void run_case() {
    int N, M;
    cin >> N >> M;
    vector<string> adj(N);

    for (auto &row : adj)
        cin >> row;

    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++)
            if (adj[i][j] == adj[j][i]) {
                cout << "YES" << '\n';
                vector<int> path;

                for (int x = 0; x <= M; x++)
                    path.push_back(x % 2 == 0 ? i : j);

                output_vector(path, true);
                return;
            }

    if (M % 2 != 0) {
        cout << "YES" << '\n';
        vector<int> path;

        for (int x = 0; x <= M; x++)
            path.push_back(x % 2 == 0 ? 0 : 1);

        output_vector(path, true);
        return;
    }

    if (N == 2) {
        cout << "NO" << '\n';
        return;
    }

    cout << "YES" << '\n';
    int a = 0, b = 1, c = 2;

    while (adj[a][b] != adj[b][c]) {
        a = (a + 1) % 3;
        b = (b + 1) % 3;
        c = (c + 1) % 3;
    }

    vector<int> cycle = {a, b, c, b};
    int start = M % 4 == 2 ? 0 : 1;
    vector<int> path;

    for (int x = 0; x <= M; x++)
        path.push_back(cycle[(start + x) % 4]);

    output_vector(path, true);
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