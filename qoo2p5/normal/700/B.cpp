#include <bits/stdc++.h>

using namespace std;

#define ll long long
const double EPS = 1e-9;
const int INF = 1e9;
const ll LINF = 1e18;

const int N = 2e5 + 123;

int n, k;
vector<int> g[N];
int a[N];
int cnt[N];

ll ans;

void solve(int v, int from = -1) {
    cnt[v] = a[v];
    for (int u : g[v]) {
        if (u != from) {
            solve(u, v);
            ans += min(cnt[u], 2 * k - cnt[u]);
            cnt[v] += cnt[u];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> k;
    
    for (int i = 0; i < 2 * k; i++) {
        int u;
        cin >> u;
        a[u]++;
    }
    
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    
    solve(1);
    
    cout << ans << "\n";
    
    return 0;
}