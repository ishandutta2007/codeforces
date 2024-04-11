#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e6+4;
int n=4, q, d[mxN], anc[mxN][20];
ar<int, 3> di={2, 1, 2};

int lca(int u, int v) {
	if (d[u]>d[v])
		swap(u, v);
	for (int i=19; ~i; --i)
		if (d[u]<=d[v]-(1<<i))
			v=anc[v][i];
	if (u==v)
		return u;
	for (int i=19; ~i; --i)
		if (anc[u][i]^anc[v][i])
			u=anc[u][i], v=anc[v][i];
	return anc[u][0];
}

int dist(int u, int v) {
	return d[u]+d[v]-2*d[lca(u, v)];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	d[1]=d[2]=d[3]=1;
	cin >> q;
	while(q--) {
		int u;
		cin >> u, --u;
		d[n]=d[n+1]=d[u]+1;
		anc[n][0]=anc[n+1][0]=u;
		for (int i=1; i<20; ++i)
			anc[n][i]=anc[n+1][i]=anc[anc[n][i-1]][i-1];
		int a=di[1], b=di[2];
		di=max(di, {dist(a, n), a, n});
		di=max(di, {dist(b, n), b, n});
		n+=2;
		cout << di[0] << "\n";
	}
	return 0;
}