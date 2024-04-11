#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <random>
#include <bitset>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using ld = long double;

const int M = 500005;
int g[M][26], sl[M];
ll c1[M], c2[M];
int f[M];
int cn = 2;

void add(int v, string &s) {
    for (char ch : s) {
        int c = ch - 'a';
        if (!g[v][c])
            g[v][c] = cn++;
        v = g[v][c];
    }
    f[v]++;
}

void bfs(int v) {
    queue<int> q;
    q.push(v);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        rep(i, 26) {
            int w = (u == v ? v : g[sl[u]][i]);
            if (g[u][i]) {
                sl[g[u][i]] = w;
                f[g[u][i]] += f[w];
                q.push(g[u][i]);
            }
            else
                g[u][i] = w;
        }
    }
}

int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
	string t;
    int n;
    cin >> t >> n;
    string s;
    rep(i, n) {
        cin >> s;
        add(0, s);
        reverse(all(s));
        add(1, s);
    }
    bfs(0);
    bfs(1);
    int m = t.size(), v = 0;
    rep(i, m) {
        v = g[v][t[i] - 'a'];
        c1[i] = f[v];
    }
    v = 1;
    for (int i = m - 1; i >= 0; i--) {
        v = g[v][t[i] - 'a'];
        c2[i] = f[v];
    }
    ll ans = 0;
    rep(i, m - 1)
        ans += c1[i] * c2[i + 1];
    cout << ans;
}