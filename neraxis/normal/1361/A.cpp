#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

const int N = 500005;

vector<int> g[N];
int n, m;
int t[N], tt[N];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    for (int i = 1; i <= n; i++) {
        cin >> t[i];
    }
    bool ok = 1;
    for (int i = 1; i <= n; i++) {
        for (int e : g[i]) if (t[i] == t[e]) ok = 0;
        set<int> v;
        for (int e : g[i]) v.insert(t[e]);
        v.insert(1e9);
        int cur = 0;
        for (int e : v) {
            if (e != cur + 1) {
                tt[i] = cur + 1;
                break;
            } 
            cur = e;
        }
        if (v.size() == 0) tt[i] = 1;
    }

    for (int i = 1; i <= n; i++) if (tt[i] != t[i]) ok = 0;
    if (!ok) cout << -1;
    else {
        vector<ii> v;
        for (int i = 1; i <= n; i++) {
            v.pb({t[i], i});
        }
        sort(all(v));
        for (ii e : v) cout << e.y << ' ';
    }
    return 0;
}