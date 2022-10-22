#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5;
int n, d[mxN], anc[mxN][18];
ar<int, 3> b;

int lca(int u, int v) {
	if (d[u]>d[v])
		swap(u, v);
	for (int i=17; ~i; --i)
		if (d[u]<=d[v]-(1<<i))
			v=anc[v][i];
	if (u==v)
		return u;
	for (int i=17; ~i; --i)
		if (anc[u][i]^anc[v][i])
			u=anc[u][i], v=anc[v][i];
	return anc[u][0];
}

int di(int u, int v) {
	return d[u]+d[v]-2*d[lca(u, v)];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i=1; i<n; ++i) {
		cin >> anc[i][0], --anc[i][0];
		d[i]=d[anc[i][0]]+1;
		for (int j=1; j<18; ++j)
			anc[i][j]=anc[anc[i][j-1]][j-1];
		int x=b[1], y=b[2];
		b=max(b, {di(i, x), i, x});
		b=max(b, {di(i, y), i, y});
		cout << b[0] << " ";
	}
	return 0;
}