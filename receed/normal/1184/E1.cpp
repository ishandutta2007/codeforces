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

const int N = 100001;
int p[N];
vector<pair<int, int>> g[N];
int mx;

int getp(int v) {
    if (p[v] != v)
        p[v] = getp(p[v]);
    return p[v];
}

int dfs(int v, int t, int pr) {
    if (v == t)
        return 1;
    for (auto &pp : g[v])
        if (pp.first != pr && dfs(pp.first, t, v)) {
            mx = max(mx, pp.second);
            return 1;
        }
    return 0;
}

int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        p[i] = i;
    vector<vector<int>> e(m, vector<int>(3));
    rep(i, m)
        cin >> e[i][1] >> e[i][2] >> e[i][0];
    sort(e.begin() + 1, e.end());
    for (int i = 1; i < m; i++) {
        int v1 = getp(e[i][1]), v2 = getp(e[i][2]);
        if (v1 != v2) {
            p[v1] = v2;
            g[v1].push_back({v2, e[i][0]});
            g[v2].push_back({v1, e[i][0]});
        }
    }
    if (!dfs(e[0][1], e[0][2], -1))
        cout << (int) 1e9;
    else
        cout << mx << '\n';
}