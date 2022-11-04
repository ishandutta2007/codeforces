#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define Test(tt) cout << "Case #" << tt << ": "
 
 
using namespace std;




int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    int i, n, m, XS, YS, XF, YF;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> m >> XS >> YS >> XF >> YF;

    vector<int> x(m), y(m), xs, ys;
    for(i = 0; i < m; i++) {
    	cin >> x[i] >> y[i];
    	xs.push_back(x[i]);
    	ys.push_back(y[i]);
    }

    sort(xs.begin(), xs.end());
    xs.resize(unique(xs.begin(), xs.end()) - xs.begin());
    sort(ys.begin(), ys.end());
    ys.resize(unique(ys.begin(), ys.end()) - ys.begin());

    int szx = (int)xs.size(), szy = (int)ys.size();
    int S = szx + szy + 1, D = szx + szy + 2;
    vector<vector<pair<int, int>>> g(D + 1);

    for(i = 0; i < szx; i++) {
    	if(i + 1 < szx) {
    		g[i + 1].push_back({i + 2, xs[i + 1] - xs[i]});
    		g[i + 2].push_back({i + 1, xs[i + 1] - xs[i]});
    	}
    }
    for(i = 0; i < szy; i++) {
		if(i + 1 < szy) {
    		g[i + 1 + szx].push_back({i + 2 + szx, ys[i + 1] - ys[i]});
    		g[i + 2 + szx].push_back({i + 1 + szx, ys[i + 1] - ys[i]});
    	}
    }
    for(i = 0; i < m; i++) {
    	int idx = lower_bound(xs.begin(), xs.end(), x[i]) - xs.begin() + 1;
    	int idy = lower_bound(ys.begin(), ys.end(), y[i]) - ys.begin() + 1 + szx;
    	g[idx].push_back({idy, 0});
    	g[idy].push_back({idx, 0});
    }

    for(i = 0; i < szx; i++) {
    	g[S].push_back({i + 1, abs(xs[i] - XS)});
    	g[i + 1].push_back({S, abs(xs[i] - XS)});
    }
	for(i = 0; i < szy; i++) {
    	g[S].push_back({i + 1 + szx, abs(ys[i] - YS)});
    	g[i + 1 + szx].push_back({S, abs(ys[i] - YS)});
    }

    priority_queue<pair<ll, int>> pq;
    pq.push({0, S});

    vector<ll> dist(D + 1, 1e18);
    vector<bool> vis(D + 1);
    dist[S] = 0;

    while(pq.size()) {
    	auto cur = pq.top();
    	pq.pop();

    	if(vis[cur.second]) continue;
    	vis[cur.second] = 1;

    	for(auto it : g[cur.second]) {
    		if(dist[it.first] > -cur.first + it.second) {
    			dist[it.first] = -cur.first + it.second;
    			pq.push({-dist[it.first], it.first});
    		}
    	}
    }

    ll ans = abs(XS - XF) + abs(YS - YF);
    for(i = 0; i < m; i++) {
    	int idx = lower_bound(xs.begin(), xs.end(), x[i]) - xs.begin() + 1;
    	int idy = lower_bound(ys.begin(), ys.end(), y[i]) - ys.begin() + 1 + szx; 
    	ans = min(ans, min(dist[idx], dist[idy]) + llabs(XF - x[i]) + llabs(YF - y[i]));
    }
    cout << ans;
 	
    return 0;
}