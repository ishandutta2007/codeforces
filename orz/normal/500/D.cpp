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

const int MX = 100 * 1000 + 7;

int a[MX], b[MX], l[MX];

vector<int> g[MX];
int sz[MX];

int n;

ll cf(int u, int v) {
    int x = min(sz[u], sz[v]);
    return 1ll * x * (n - x);
}

void dfs(int v, int p) {
    sz[v] = 1;
    for (int to : g[v]) {
        if (to != p) {
            dfs(to, v);
            sz[v] += sz[to];
        }
    }
}

int main() {
#ifdef FASTIO
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> a[i] >> b[i] >> l[i];
        g[a[i]].push_back(b[i]);
        g[b[i]].push_back(a[i]);
    }

    dfs(1, 1);
    ll tot = 0;
    for (int i = 1; i < n; i++) {
        tot += cf(a[i], b[i]) * l[i];
    }

    ll al = 1ll * n * (n - 1) / 2;

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        tot -= cf(a[x], b[x]) * l[x];
        l[x] = y;
        tot += cf(a[x], b[x]) * l[x];
        ld ans = 3.0 * tot / al;
        cout.precision(20);
        cout << fixed << ans << "\n";
    }
    return 0;
}