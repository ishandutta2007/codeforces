#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); i++)
#define R(i, j, k) for(int i = (j); i >= (k); i--)
#define ll long long
#define sz(a) ((int) a.size()) 
#define vi vector<int>
using namespace std;
const int N = 1e5 + 7; 
int B, n, m, k, fa[N], mx[N], val[N];
int ehd[N], ev[N * 2], enx[N * 2], eid;
void eadd(int u, int v) {
	++eid, enx[eid] = ehd[u], ev[eid] = v, ehd[u] = eid;
}
int qwq, t[N], tp;
void pr(int x) { 
	for(int i = ehd[x]; i; i = enx[i]) if(ev[i] != fa[x]) fa[ev[i]] = x, pr(ev[i]); 
	t[++tp] = x;
}
int calc(int x) {
	qwq = 0, k = x;
	L(a, 1, tp) {
		int x = t[a], Mx1 = 0, Mx2 = 0;
		for(int i = ehd[x]; i; i = enx[i]) Mx1 = Mx1 < mx[ev[i]] ? (Mx2 = Mx1, mx[ev[i]]) : ((Mx2 = Mx2 < mx[ev[i]] ? mx[ev[i]] : Mx2), Mx1);
		mx[x] = Mx1 + Mx2 + 1 >= k ? (++qwq, 0) : Mx1 + 1;
	}
	return qwq;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n, B = sqrt(n) * 3.5, B = min(B, n);
	L(i, 1, n - 1) {
		int u, v;
		cin >> u >> v;
		eadd(u, v), eadd(v, u);
	}
	pr(1);
	eid = 0, memset(ehd, 0, sizeof(ehd));
	L(i, 2, n) eadd(fa[i], i);
	L(i, 1, B) k = i, val[i] = calc(i);
	int lst = B + 1;
	R(i, val[B], 1) {
		int l = lst, r = n, ns = lst - 1;
		while(l <= r) {
			int mid = (l + r) >> 1;
			if(calc(mid) >= i) ns = mid, l = mid + 1;
			else r = mid - 1;
		}
		while(lst <= ns) val[lst] = i, ++lst;
	}
	L(i, 1, n) cout << val[i] << "\n";
	return 0;
}