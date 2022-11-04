#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = (int) 1e9 + 123;
const ll LINF = (ll) 1e18 + 123;

#define sz(x) (int) (x).size()

void run();

int main() {
#ifndef LOCAL
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#endif
    run();
    return 0;
}

const int N = (int) 1e5 + 123;

int n;
vector<int> g[N];
char ans[N];
bool vis[N];

int find(int v, int &x, int sz, int from = -1) {
    int cur = 1;
    for (int u : g[v]) {
        if (u == from || vis[u]) continue;
        cur += find(u, x, sz, v);
    }
    
    if (x == -1 && (from == -1 || cur >= sz / 2)) {
        x = v;
    }
    
    return cur;
}

void solve(int v, int sz = n, int level = 0) {
    int c = -1;
    find(v, c, sz);
    assert(c != -1);
    vis[c] = 1;
    ans[c] = (char) ('A' + level);
    
    for (int u : g[c]) {
        if (!vis[u]) {
            solve(u, sz / 2, level + 1);
        }
    }
}

void run() {
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    solve(1);
    
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
}