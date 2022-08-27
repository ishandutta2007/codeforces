#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 1 << 20, M = 2e7 + 7;
int n, lim, a[N], f[N], ns[N], idt;
int tot, ehd[M], deg[M], ev[M << 1], enx[M << 1], eid;
void eadd (int u, int v) {
	++eid, ev[eid] = v, enx[eid] = ehd[u], ehd[u] = eid;
	deg[v] += 1;
}
bool vis[N];
void topo () {
	queue < int > q;
	L(i, 1, tot) if(!deg[i]) q.push(i);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		if(u <= n) ns[u] = ++idt;
		for (int i = ehd[u]; i; i = enx[i]) {
			deg[ev[i]] -= 1;
			if(!deg[ev[i]]) q.push(ev[i]);
		}
	}
} 
void ins (int i) {
	for (int x = i + lim; x; x >>= 1) 
		++tot, (f[x] && (eadd(f[x], tot), 0)), eadd(i, tot), f[x] = tot;
}
void lk (int x, int l, int r) {
	if (l > r) return ;
	for (l += lim - 1, r += lim + 1; l ^ r ^ 1; l >>= 1, r >>= 1) {
		if((!(l & 1)) && f[l ^ 1]) eadd (f[l ^ 1], x);
		if((r & 1) && f[r ^ 1]) eadd (f[r ^ 1], x); 
	}
}
int main () {
	ios :: sync_with_stdio(false);
	cin.tie (0); cout.tie (0);
	cin >> n;
	for (lim = 1; lim <= n; lim <<= 1) ;
	L(i, 1, n) {
		cin >> a[i];
		if(a[i] > 0) vis[a[i]] = true;
	}
	tot = n;
	L(i, 1, n) if(!vis[i]) ins (i);
	R(i, n, 1) if(a[i] > 0) {
		lk (i, 1, min(i, a[i]) - 1);
		lk (i, i + 1, a[i] - 1);
		ins (a[i]);
		eadd (i, a[i]);
	} else {
		lk (i, 1, i - 1);
		lk (i, i + 1, n);
	} 
	topo();
	L(i, 1, n) cout << ns[i] << ' ';
	cout << '\n';
	return 0;
}