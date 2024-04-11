#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <unordered_set>
#include <fstream>
#include <cstring>
#include <map>

#define ll long long
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()
using namespace std;
ll MOD = 1e9 + 7;
ll sub(ll a, ll b) {
    if (a - b < 0) return a - b + MOD;
    return a - b;
}

ll add(ll a, ll b) {
    if (a + b >= MOD) return a + b - MOD;
    return a + b;
}

ll mul(ll a, ll b) {
    return a * b % MOD;
}


int n, m;
map<int, ll> g[100001];
map<int, ll> gr[100001];

void solve() {
    cin >> n >> m;
    int m1 = m;
    range(i, m1) {
        int u, v;
        ll d;
        cin >> u >> v >> d;
        if (g[u][v]) {
            m--;
        }
        g[u][v] += d;
        gr[v][u] += d;
    }
    range(_, 2) {
        for (int i = 1; i <= n; ++i) {
            while (!g[i].empty() && !gr[i].empty()) {
                int u1 = (*g[i].begin()).first;
                ll w1 = (*g[i].begin()).second;
                int u2 = (*gr[i].begin()).first;
                ll w2 = (*gr[i].begin()).second;
                if (w1 < w2) {
                    g[i].erase(u1);
                    gr[u1].erase(i);
                    gr[i][u2] -= w1;
                    g[u2][i] -= w1;
                    if (u1 != u2) {
                        g[u2][u1] += w1;
                        gr[u1][u2] += w1;
                    } else {
                        m--;
                    }
                } else {
                    gr[i].erase(u2);
                    g[u2].erase(i);
                    g[i][u1] -= w2;
                    gr[u1][i] -= w2;
                    if (g[i][u1] == 0) {
                        g[i].erase(u1);
                        gr[u1].erase(i);
                        m--;
                    }
                    if (u1 != u2) {
                        g[u2][u1] += w2;
                        gr[u1][u2] += w2;
                    } else {
                        m--;
                    }
                }
            }
        }
    }
    ll a = 0;
    range(i, n + 1) {
        a += g[i].size();
    }
    cout << a << '\n';
    range(i, n + 1) {
        for(auto p: g[i]) {
            cout << i << ' ' << p.first << ' ' << p.second << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tests;
    tests = 1;
    range(i, tests) {
        solve();
    }
    return 0;
}