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

double ans;
int n;
vector<int> g[N];

void dfs(int v, int p = -1, int h = 1) {
    ans += 1.0 / h;
    for (int u : g[v]) {
        if (u != p) dfs(u, v, h + 1);
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
    dfs(1);
    cout << fixed << setprecision(15) << ans << "\n";
}