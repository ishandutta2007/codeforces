#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 1e6 + 7;
const ll inf = 1e18;
int n, m, f[N], vis[N], ans, ehd[N], ev[N], enx[N], eid;
ll ew[N], dis[N];
void eadd(int u, int v, ll w) {
	++eid, enx[eid] = ehd[u], ev[eid] = v, ew[eid] = w, ehd[u] = eid;
}
void dij() {
	priority_queue< pair<ll, int> > q;
	q.push(mkp(0, n + 1)), fill(dis + 1, dis + n + 1, inf);
	while(! q.empty()) {
		int u = q.top().second;
		q.pop();
		if(vis[u]) continue;
		vis[u] = true;
		for(int i = ehd[u]; i; i = enx[i]) 
			if(dis[ev[i]] > dis[u] + ew[i]) dis[ev[i]] = dis[u] + ew[i], q.push(mkp(- dis[ev[i]], ev[i]));
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	L(i, 1, m) {
		int u, v; ll w;
		cin >> u >> v >> w;
		eadd(u, v, w * 2);
		eadd(v, u, w * 2);
	}
	L(i, 1, n) cin >> dis[i], eadd(n + 1, i, dis[i]);
	dij();
	L(i, 1, n) cout << dis[i] << " ";
	return 0;
}