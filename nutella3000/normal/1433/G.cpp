
#include <bits/stdc++.h>
 
 
using namespace std;
#define int long long
#define inf (1e9 + 7)
#define INF (int)1e17
#define pii pair<int,int>
#define AIDAR ASADULLIN
#define all(x) x.begin(), x.end()
#define skip continue
# define fs first
#define sc second
 
vector<vector<pii>> a;
 
void dijkstra(vector<int> &d, int n, int s) {
    for (int i = 0; i < n; i++) {
        d[i] = inf;
    }
    d[s] = 0;
    set <pii> pq;
    pq.emplace(0, s);
    while (!pq.empty()) {
        auto x = (*pq.begin());
        pq.erase(pq.begin());
        for (auto to : a[x.second]) {
            if (d[to.fs] > x.fs + to.sc) {
                d[to.fs] = x.fs + to.sc;
                pq.emplace(d[to.fs], to.fs);
            }
        }
    }
}
 
signed main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> www; // edges
    a.assign(n, vector<pii >(0, {0, 0}));
    for (int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        x--, y--;
        www.push_back({x, y, w});
        a[x].emplace_back(y, w);
        a[y].emplace_back(x, w);
    }
    vector<pii > v(k, {0, 0});
    for (int i = 0; i < k; i++) {
        cin >> v[i].first >> v[i].second;
        v[i].first--, v[i].second--;
    }
    vector<vector<int>> d(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        dijkstra(d[i], n, i);
    }
    int ans = inf;
    for (int i = 0; i < m; i++) {
        int loc = 0;
        for (auto x : v) {
            int loci = d[x.fs][www[i][0]] + d[x.sc][www[i][1]];
            loci = min(loci, d[x.sc][www[i][0]] + d[x.fs][www[i][1]]);
            loci = min(loci, d[x.fs][x.sc]);
            loc += loci;
        }
        ans = min(ans, loc);
    }
    cout << ans;
}