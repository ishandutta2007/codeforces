#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, d, a[100], x[100], y[100];
inline int cost(int i, int j) {return a[j]-d*(abs(x[i]-x[j])+abs(y[i]-y[j]));}

bool vis[100];
int dis[100];
bool ok(int x) {
	memset(vis, 0, sizeof(vis));
	fill(dis, dis+n, -2e9);
	dis[0]=x;
	priority_queue<pair<int, int>> q;
	q.push({0, 0});
	while(q.size()) {
		int u=q.top().second; q.pop();
		assert(dis[u]>=0);
		if (vis[u]) continue;
		vis[u]=1;
		for (int i=0; i<n; ++i) {
			if (vis[i]) continue;
			int nxt=dis[u]+cost(u, i);
			if (nxt>dis[i]&&nxt>=0)
				q.push({dis[i]=nxt, i});
		}
	}
	return vis[n-1];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> d;
	for (int i=1; i<n-1; ++i)
		cin >> a[i];
	for (int i=0; i<n; ++i)
		cin >> x[i] >> y[i];
	int l=0, r=1e9;
	while(l<r) {
		int mid=(l+r)/2;
		if (ok(mid)) r=mid;
		else l=mid+1;
	}
	cout << l;
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/