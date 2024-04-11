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

const int N = (int) 3e5 + 123;

int n;
int a[N];
vector<int> g[N];

void run() {
    cin >> n;
    multiset<int> q;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        q.insert(a[i] + 2);
    }
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    int ans = INF;
    
    for (int v = 0; v < n; v++) {
        q.erase(q.find(a[v] + 2));
        int cur = a[v];
        for (int u : g[v]) {
            cur = max(cur, a[u] + 1);
            q.erase(q.find(a[u] + 2));
        }
        cur = max(cur, q.empty() ? -INF : *q.rbegin());
        ans = min(ans, cur);
        q.insert(a[v] + 2);
        for (int u : g[v]) {
            q.insert(a[u] + 2);
        }
    }
    cout << ans << "\n";
}