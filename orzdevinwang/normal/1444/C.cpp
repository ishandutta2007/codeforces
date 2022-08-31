#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j), i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = (j), i##E = k; i >= i##E; i--)
#define mkp make_pair
#define pii pair<int, int>
#define ll long long
#define db double
#define sz(a) a.size()
#define x first
#define y second
#define vi vector<int>
using namespace std;
const int N = 2e6 + 7;
struct UFS {
	stack < int > stk;
	int siz[N], f[N];
	void init(int x) {
		L(i, 1, x) f[i] = i, siz[i] = 1;
	}
	int find(int x) {
		return f[x] == x ? x : find(f[x]);
	}
	bool merge(int x, int y) {
		x = find(x), y = find(y);
		if(x == y) return false;
		if(siz[x] > siz[y]) swap(x, y);
		f[x] = y, siz[y] += siz[x], stk.push(x);
		return true;
	}
	void revoke() {
		int u = stk.top();
		siz[f[u]] -= siz[u], f[u] = u, stk.pop();
	}
} ufs;
int n, m, k, ok[N], u[N], v[N], a[N], tot;
struct node { 
	int u, v, id; 
} ask[N];
ll ans;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> k, ufs.init(n * 2);
	L(i, 1, n) {
		cin >> a[i];
		if(a[i] > k) assert(0);	
	}
	L(i, 1, k) ok[i] = true;
	L(i, 1, m) {
		cin >> u[i] >> v[i];
		if(a[u[i]] == a[v[i]]) {
			if(ufs.find(u[i]) == ufs.find(v[i])) ok[a[u[i]]] = false;
			ufs.merge(u[i], v[i] + n), ufs.merge(u[i] + n, v[i]);
		} 
	} 
	L(i, 1, m) if(a[u[i]] != a[v[i]] && ok[a[u[i]]] && ok[a[v[i]]]) {
		++tot, ask[tot].u = a[u[i]], ask[tot].v = a[v[i]], ask[tot].id = i;
		if(ask[tot].u > ask[tot].v) swap(ask[tot].u, ask[tot].v);
	}
	int cnt = 0;
	L(i, 1, k) if(ok[i]) cnt++;
	ans = (ll) cnt * (cnt - 1) / 2;
	sort(ask + 1, ask + tot + 1, [&] (node aa, node bb) { return aa.v == bb.v ? aa.u < bb.u : aa.v < bb.v; });
	int ent = 0, can = false;
	
	L(i, 1, tot) {
		int fu = u[ask[i].id], fv = v[ask[i].id];
		if(ufs.find(fu) == ufs.find(fv)) can = true;
		ent += ufs.merge(fu, fv + n) + ufs.merge(fu + n, fv);
		if(i == tot || ask[i].u != ask[i + 1].u || ask[i].v != ask[i + 1].v) {
			while(ent) ufs.revoke(), --ent;
			ans -= can, can = false;
		}
	}
	cout << ans << "\n";
	return 0;
}