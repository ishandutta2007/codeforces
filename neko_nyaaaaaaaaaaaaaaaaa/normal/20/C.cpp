// Dijkstra with path-tracing
// http://codeforces.com/contest/20/problem/C
// Start = 1, end = n

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll INF = 0x3f3f3f3f3f3f3f3fLL;

ll n, m;
vector<ll> vis(200007);
vector<vector<pair<ll, ll>>> adj(200007);
vector<ll> dist(200007, INF);
vector<ll> previous(200007, -1);

void dijkstra(ll start) {

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
    dist[1] = 0;
    q.push({0, 1});

    while (!q.empty()) {
        pair<ll, ll> a = q.top();
        q.pop();
        if (vis[a.second]) continue;
        vis[a.second] = 1;

        ll val = a.first;
        ll now = a.second;

        for (auto k : adj[now]) {
            if (dist[k.first] > dist[now] + k.second) {
                dist[k.first] = dist[now] + k.second;       // {node, weight}
                previous[k.first] = now;        // fix this

                q.push({dist[k.first], k.first});
            }
        }
    }

}

int main() {
    ios::sync_with_stdio(0);

    cin >> n >> m;
    ll x, y, w;
    while (m--) {
        cin >> x >> y >> w;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }

    dijkstra(1);             // add parameter

    if (dist[n] == INF) {cout << -1; return 0;}

//    cout << dist[n] << endl;

//    for (int i = 1; i <= n; i++) {
//        cout << previous[i] << " ";
//    }
//    cout << endl;

    vector<ll> ans;
    ll trace = n;
    while (previous[trace] != -1) {
        ans.push_back(trace);
        trace = previous[trace];
    }
    ans.push_back(1);
    reverse(ans.begin(), ans.end());

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}