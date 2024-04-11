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


const int N = 32;

int power(int a, int b) {
    int p = 1;

    while (b-- > 0)
        p *= a;

    return p;
}

int main() {
    int L, R;
    cin >> L >> R;
    int K = R - L + 1;

    vector<array<int, 2>> ranges(N, {-1, -1});
    ranges[0] = {0, 1};
    vector<vector<int>> adj(N, vector<int>(N, -1));

    int have = 1;
    int where = 1;
    int next = 1;

    while (have + next <= K) {
        have += next;

        if (where % 2 != 0) {
            if (where == 1) {
                adj[0][1] = 1;
                ranges[1] = {1, 2};
            } else {
                int add = power(3, where / 2);
                adj[where - 2][where] = add;
                adj[where - 1][where] = add;
                ranges[where] = {ranges[where - 2][0] + add, ranges[where - 1][1] + add};
            }

            next *= 2;
        } else {
            if (where == 2) {
                adj[0][2] = 2;
                adj[1][2] = 2;
                ranges[2] = {2, 4};
            } else {
                int add = 2 * power(3, (where - 1) / 2);
                adj[where - 3][where] = add;
                adj[where - 2][where] = add;
                adj[where - 1][where] = add;
                ranges[where] = {ranges[where - 3][0] + add, ranges[where - 1][1] + add};
            }

            next = next / 2 * 3;
        }

        where++;
    }

    int need = K - have;

    for (int i = where - 1; i >= 0; i--) {
        int length = ranges[i][1] - ranges[i][0];

        if (length > 0 && need >= length) {
            int add = have - ranges[i][0];
            adj[i][where] = add;

            if (ranges[where][0] < 0)
                ranges[where] = {ranges[i][0] + add, ranges[i][1] + add};
            else
                ranges[where][1] = ranges[i][1] + add;

            have += length;
            need -= length;
            assert(have == ranges[where][1]);
            // where++;
        }
    }

    cout << "YES" << '\n';
    vector<array<int, 3>> edges;

    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++)
            if (adj[i][j] > 0)
                edges.push_back({i, j, adj[i][j]});

    where++;

    for (int i = 0; i < N; i++)
        if (ranges[i][1] - ranges[i][0] > 0)
            edges.push_back({i, where, L});

    cout << where + 1 << ' ' << edges.size() << '\n';

    for (auto &e : edges)
        cout << e[0] + 1 << ' ' << e[1] + 1 << ' ' << e[2] << '\n';
}