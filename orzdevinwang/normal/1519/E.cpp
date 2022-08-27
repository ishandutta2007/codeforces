#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); i++) 
#define R(i, j, k) for(int i = (j); i >= (k); i--)
#define ll long long
#define sz(a) ((int) a.size())
#define vi vector<int>
using namespace std;
const int N = 4e5 + 7;
int n, f[N], ns, ns1[N], ns2[N];
struct point {
	ll a, b, c, d;
	point up() {
		point res = (*this);
		res.a += res.b;
		return res;
	}
	point rig() {
		point res = (*this);
		res.c += res.d;
		return res;
	}
	void upd() {
		ll g;
		g = __gcd(a, b), a /= g, b /= g;
		g = __gcd(c, d), c /= g, d /= g;
	}
	pair < ll, ll > sss () {
		ll x = a * d, y = b * c, g = __gcd(x, y);
		return make_pair(x / g, y / g);
	}
} a[N];
map < pair <ll, ll> , int > mp;
void get(int u, int v) {
	++ns, ns1[ns] = u, ns2[ns] = v;
}
int find(int x) {
	return f[x] == x ? x : f[x] = find(f[x]);
}
int tot, s1[N], s2[N];
vi o[N];
int ehd[N], ev[N], ew[N], enx[N], eid;
void eadd(int u, int v, int w) {
	++eid, enx[eid] = ehd[u], ev[eid] = v, ew[eid] = w, ehd[u] = eid;
}
bool vis[N], use[N];
void dfs(int u, int fa, int ls) {
	vis[u] = true;
	for(int i = ehd[u]; i; i = enx[i]) if(ev[i] != fa) dfs(ev[i], u, ew[i]);
	int cnt = 0, su = 0;
	for(const int &x : o[u]) if(!use[x]) ++cnt;
	for(const int &x : o[u]) {
		if(use[x] || cnt % 2 == 1 && x == ls) continue;
		use[x] = true;
		if(!su) su = x;
		else get(su, x), su = 0;
	}
	if(su && ls) assert(0);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	L(i, 1, n * 2) f[i] = i;
	L(i, 1, n) {
		cin >> a[i].a >> a[i].b >> a[i].c >> a[i].d, a[i].upd();
		int u;
		u = mp[a[i].up().sss()];
		if(!u) u = mp[a[i].up().sss()] = ++tot;
		o[u].push_back(i), s1[i] = u;
		u = mp[a[i].rig().sss()];
		if(!u) u = mp[a[i].rig().sss()] = ++tot;
		o[u].push_back(i), s2[i] = u;
		if(find(s1[i]) != find(s2[i])) 
			eadd(s1[i], s2[i], i), eadd(s2[i], s1[i], i), f[find(s1[i])] = s2[i];
	}
	L(i, 1, tot) if(!vis[i]) dfs(i, 0, 0);
	cout << ns << "\n";
	L(i, 1, ns) cout << ns1[i] << " " << ns2[i] << "\n";
	return 0;
}
/*
2
78 72 45 72
148 12 105 6
*/