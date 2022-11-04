#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double ld;

const ll INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld EPS = 1e-9;

#define TASK ""

const int N = 2000;
const int M = 10000;

struct Edge {
    int u, v;
    ll cost;
    
    Edge() {}
    
    Edge(int u, int v, ll cost) : u(u), v(v), cost(cost) {}
    
    int get_next(int w) const {
        return w == u ? v : u;
    }
};

int n, m, l, s, t;
vector<int> g[N];
Edge edge[M];

ll dp[N];
bool used[N];
pair<int, int> p[N];

void dijkstra() {
    fill(dp, dp + N, LINF);
    fill(used, used + N, false);
    dp[s] = 0;
    
    priority_queue<pair<ll, int>> q;
    q.push(make_pair(0, s));
    
    while (!q.empty()) {
        int v = q.top().second;
        q.pop();
        
        if (used[v]) {
            continue;
        }
        
        used[v] = true;
        
        for (int eid : g[v]) {
            Edge &e = edge[eid];
            int u = e.get_next(v);
            
            if (dp[v] + e.cost < dp[u]) {
                dp[u] = dp[v] + e.cost;
                p[u] = {v, eid};
                q.push(make_pair(-dp[u], u));
            }
        }
    }
}

int run() {
    cin >> n >> m >> l >> s >> t;
    vector<int> a;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        
        if (w == 0) {
            a.push_back(i);
        }
        
        edge[i] = Edge(u, v, w);
        g[v].push_back(i);
        g[u].push_back(i);
    }
    
    for (int i : a) {
        edge[i].cost = LINF;
    }
    
    dijkstra();
    ll MAX = dp[t];
    
    for (int i : a) {
        edge[i].cost = 1;
    }
    
    dijkstra();
    ll MIN = dp[t];
    
    if (!(MIN <= l && l <= MAX)) {
        cout << "NO\n";
        return 0;
    }
    
    int k = (int) a.size();
    
    int left = -1;
    int right = k;
    
    while (right - left > 1) {
        int mid = (left + right) / 2;
        
        for (int i = 0; i < mid; i++) {
            edge[a[i]].cost = 1;
        }
        for (int i = mid; i < k; i++) {
            edge[a[i]].cost = LINF;
        }
        
        dijkstra();
        if (dp[t] <= l) {
            right = mid;
        } else {
            left = mid;
        }
    }
    
    for (int i = 0; i < right; i++) {
        edge[a[i]].cost = 1;
    }
    for (int i = right; i < k; i++) {
        edge[a[i]].cost = LINF;
    }
    
    dijkstra();
    
    if (right > 0) {
        edge[a[right - 1]].cost += l - dp[t];
    }
    
    cout << "YES\n";
    
    for (int i = 0; i < m; i++) {
        cout << edge[i].u << " " << edge[i].v << " " << edge[i].cost << "\n";
    }

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#ifndef DEBUG
    if (strlen(TASK) > 0) {
        freopen(TASK ".in", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }
#endif

    return run();
}