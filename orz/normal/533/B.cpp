#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

#define FASTIO
#define ALL(v) (v).begin(), (v).end()
#define rep(i, l, r) for (int i = (l); i < (r); ++i)

#ifdef FASTIO
#define scanf abacaba
#define printf abacaba
#endif

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;

const int MX = 200 * 1000 + 7;
const ll INF = 1e18;
vector<int> g[MX];
ll a[MX];
ll f[MX][2];

void dfs(int v) {
    f[v][1] = -INF;
    for (int to : g[v]) {
        dfs(to);
        ll g0 = max(f[v][0] + f[to][0], f[v][1] + f[to][1]);
        ll g1 = max(f[v][1] + f[to][0], f[v][0] + f[to][1]);
        f[v][0] = g0;
        f[v][1] = g1;
    }
    f[v][1] = max(f[v][1], f[v][0] + a[v]);
}

int main() {
#ifdef FASTIO
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
    int n;
    cin >> n;
    int root = -1;
    for (int i = 1; i <= n; i++) {
        int p;
        cin >> p >> a[i];
        if (p == -1) {
            root = i;
        } else {
            g[p].push_back(i);
        }
    }

    dfs(root);
    cout << max(f[root][0], f[root][1]) << "\n";
    return 0;
}