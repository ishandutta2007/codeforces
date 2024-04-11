#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e5;
const ll INF=1e18;
int n, q, n2, s, ls[3*mxN], rs[3*mxN];
vector<ar<int, 2>> adj[3*mxN];
ll d[3*mxN];
bool vis[3*mxN];

ar<int, 2> bld(int l=0, int r=n-1) {
	if (l==r)
		return {l, l};
	int mid=(l+r)/2;
	int u1=n2++, u2=n2++;
	ar<int, 2> a=bld(l, mid), b=bld(mid+1, r);
	ls[u1]=a[0], ls[u2]=a[1], rs[u1]=b[0], rs[u2]=b[1];
	adj[u1].push_back({a[0], 0});
	adj[u1].push_back({b[0], 0});
	adj[a[1]].push_back({u2, 0});
	adj[b[1]].push_back({u2, 0});
	return {u1, u2};
}

void upd1(int qu, int ql, int qr, int w, int u, int l=0, int r=n-1) {
	if (l>qr||r<ql)
		return;
	if (ql<=l&&r<=qr) {
		adj[qu].push_back({u, w});
		return;
	}
	int mid=(l+r)/2;
	upd1(qu, ql, qr, w, ls[u], l, mid);
	upd1(qu, ql, qr, w, rs[u], mid+1, r);
}

void upd2(int qu, int ql, int qr, int w, int u, int l=0, int r=n-1) {
	if (l>qr||r<ql)
		return;
	if (ql<=l&&r<=qr) {
		adj[u].push_back({qu, w});
		return;
	}
	int mid=(l+r)/2;
	upd2(qu, ql, qr, w, ls[u], l, mid);
	upd2(qu, ql, qr, w, rs[u], mid+1, r);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q >> s, --s;
	n2=n;
	ar<int, 2> root=bld();
	while(q--) {
		int t;
		cin >> t;
		if (t==1) {
			int u, v, w;
			cin >> u >> v >> w, --u, --v;
			adj[u].push_back({v, w});
		} else if (t==2) {
			int u, l, r, w;
			cin >> u >> l >> r >> w, --u, --l, --r;
			upd1(u, l, r, w, root[0]);
		} else {
			int u, l, r, w;
			cin >> u >> l >> r >> w, --u, --l, --r;
			upd2(u, l, r, w, root[1]);
		}
	}
	memset(d, 0x3f, sizeof(d));
	priority_queue<ar<ll, 2>, vector<ar<ll, 2>>, greater<ar<ll, 2>>> pq;
	pq.push({d[s]=0, s});
	while(!pq.empty()) {
		int u=pq.top()[1];
		pq.pop();
		if (vis[u])
			continue;
		vis[u]=1;
		for (ar<int, 2> v : adj[u])
			if (d[u]+v[1]<d[v[0]])
				pq.push({d[v[0]]=d[u]+v[1], v[0]});
	}
	for (int i=0; i<n; ++i)
		cout << (d[i]>=INF?-1:d[i]) << " ";
	return 0;
}