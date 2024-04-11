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

int n, k, d;
bool a[N];
vector<pair<int, int>> g[N];
bool want[N];
int from[N];
int dist[N];

void run() {
    cin >> n >> k >> d;
    for (int i = 0; i < k; i++) {
        int p;
        cin >> p;
        a[p - 1] = 1;
    }
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back({v, i});
        g[v].push_back({u, i});
    }
    
    fill(dist, dist + N, INF);
    
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (a[i]) q.push(i), dist[i] = 0;
    }
    
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        
        for (auto &e : g[v]) {
            int u = e.first;
            if (dist[v] + 1 < dist[u]) {
                dist[u] = dist[v] + 1;
                q.push(u);
                from[u] = e.second;
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (a[i]) continue;
        want[from[i]] = 1;
    }
    
    vector<int> ans;
    for (int i = 0; i < n - 1; i++) {
        if (!want[i]) ans.push_back(i);
    }
    
    cout << ans.size() << "\n";
    for (int id : ans) {
        cout << id + 1 << " ";
    }
    cout << "\n";
}