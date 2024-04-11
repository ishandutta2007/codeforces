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
using ul = unsigned long long;
using ld = long double;

const int N = 300001;
int m1[N], m2[N];
int q, n, ans;
vector<vector<int>> g;

void dfs(int v, int p) {
    m1[v] = m2[v] = 0;
    for (int u : g[v]) {
        if (u == p)
            continue;
        dfs(u, v);
        if (m1[u] > m1[v]) {
            m2[v] = m1[v];
            m1[v] = m1[u];
        }
        else if (m1[u] > m2[v])
            m2[v] = m1[u];
    }
    ans = max(ans, m1[v] + m2[v] + (int) g[v].size() + 1);
    m1[v] += g[v].size() - 1;
}

int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> q;
    int u, v;
    rep(z, q) {
        cin >> n;
        ans = 0;
        g = vector<vector<int>>(n);
        rep(i, n - 1) {
            cin >> u >> v;
            u--; v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(0, 0);
        cout << ans << '\n';
    }
}