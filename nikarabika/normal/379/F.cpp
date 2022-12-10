#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 10, maxl = 22;
int a, b, d, q, n;
int h[maxn];
int p[maxn][maxl];

int lca(int v, int u){
	if(h[v] > h[u])
		swap(v, u);
	int dist = h[u] - h[v];
	for(int i = maxl - 1; i >= 0; i--)
		if(dist & (1 << i))
			u = p[u][i];
	if(v == u)
		return v;
	for(int i = maxl - 1; i >= 0; i--)
		if(p[v][i] != -1 and p[v][i] != p[u][i])
			v = p[v][i], u = p[u][i];
	return p[v][0];
}

int dis(int v, int u){
	int par = lca(v, u);
	return h[v] + h[u] - 2 * h[par];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	memset(p, -1, sizeof p);
	cin >> q;
	n = 4;
	p[2][0] = p[3][0] = p[4][0] = 1;
	h[1] = 0;
	h[2] = h[3] = h[4] = 1;
	a = 2, b = 3, d= 2;
	while(q--){
		int v;
		cin >> v;
		int c1 = n + 1, c2 = n + 2;
		n += 2;
		p[c1][0] = p[c2][0] = v;
		h[c1] = h[c2] = h[v] + 1;
		for(int i = 1; i < maxl and p[c1][i - 1] != -1; i++)
			p[c1][i] = p[c2][i] = p[p[c1][i - 1]][i - 1];
		int dac = dis(a, c1), dbc = dis(b, c1);
		if(dac > d)
			d = dac, b = c1;
		if(dbc > d)
			d = dbc, a = c1;
		cout << d << '\n';
	}
	return 0;
}