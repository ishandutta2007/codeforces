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

const int N = 400005, S = 26;
int g[N][S], b[N][S], num[N], cn, bn, ans[N], suf[N], cc[N], tin[N], tout[N], f[N], ct;
vector<int> sg[N];
vector<pair<int, int>> ql[N];

void add(int v, int x) {
    for (int i = v; i < N; i |= (i + 1))
        f[i] += x;
}

int sum(int v) {
    int res = 0;
    for (int i = v; i; i &= (i - 1))
        res += f[i - 1];
    return res;
}

void dfs(int v, int bv) {
    add(tin[bv], 1);
    for (auto &p : ql[v])
        ans[p.first] = sum(tout[p.second]) - sum(tin[p.second]);
    rep(i, S) {
        if (!g[v][i])
            continue;
        dfs(g[v][i], b[bv][i]);
    }
    add(tin[bv], -1);
}

void dfs2(int v) {
    tin[v] = ct++;
    for (int u : sg[v])
        dfs2(u);
    tout[v] = ct;
}

int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
	int n, q, t, x, v;
    cin >> n;
    char c;
    for (int i = 1; i <= n; i++) {
        cin >> t;
        if (t == 1)
            x = 0;
        else {
            cin >> x;
            x = num[x];
        }
        cin >> c;
        c -= 'a';
        if (!g[x][c])
            g[x][c] = ++cn;
        num[i] = g[x][c];
    }
    string s;
    cin >> q;
    rep(i, q) {
        cin >> x >> s;
        v = 0;
        for (char c : s) {
            c -= 'a';
            if (!b[v][c])
                b[v][c] = ++bn;
            v = b[v][c];
        }
        ql[num[x]].push_back({i, v});
    }
    queue<int> qu;
    qu.push(0);
    while (!qu.empty()) {
        int v = qu.front();
        qu.pop();
        rep(i, S) {
            int w = (v ? b[suf[v]][i] : 0);
            if (b[v][i]) {
                suf[b[v][i]] = w;
                sg[w].push_back(b[v][i]);
                qu.push(b[v][i]);
            }
            else
                b[v][i] = w;
        }
    }
    dfs2(0);
    dfs(0, 0);
    rep(i, q)
        cout << ans[i] << '\n';
}