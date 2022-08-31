#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); i++) 
#define R(i, j, k) for(int i = (j); i >= (k); i--)
#define ll long long
#define sz(a) ((int) a.size())
#define vi vector<int>
using namespace std;
const int N = 6e5 + 7, mod = 1e9 + 7;
int n, m, k, Q, a[N], x[N], y[N], siz[N], all[N];
int eid = 1, ehd[N];
map < int, int > mp[N];
struct edge {
	int v, w, rk, sum;
	double ed;
} e[N];
vi q[N], pr[N];
ll det(ll x1, ll y1, ll x2, ll y2) {
	return x1 * y2 - x2 * y1;
}
void eadd(int u, int v) {
	mp[u][v] = ++eid, e[eid].v = v, q[u].push_back(eid);
}
bool vis[N];
void dfs(int x) {
	vis[x] = true, siz[x] = 1;
	for(const int &i : q[x]) if(!vis[e[i].v]) 
		dfs(e[i].v), siz[x] += siz[e[i].v], e[i].w += siz[e[i].v], e[i ^ 1].w -= siz[e[i].v];
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	cin >> n >> m;
	L(i, 1, m) {
		int u, v;
		cin >> u >> v, eadd(u, v), eadd(v, u);
	}
	L(i, 1, n) cin >> x[i] >> y[i]; 
	L(u, 1, n) {
		for(const int &i : q[u]) e[i].ed = atan2(x[e[i].v] - x[u], y[e[i].v] - y[u]);
		sort(q[u].begin(), q[u].end(), [&] (int aa, int bb) { return e[aa].ed < e[bb].ed; });
//		for(const int &i : q[u]) cout << e[i].v << "_ ";
//		cout << "\n";
	}
	int rt = 1;
	L(i, 2, n) if(x[i] < x[rt]) rt = i;
	dfs(rt);
	dfs(1);
	L(u, 1, n) L(i, 0, sz(q[u]) - 1) all[u] += e[q[u][i]].w, pr[u].push_back(all[u]), e[q[u][i]].rk = i;
	cin >> Q;
	while(Q--) {
		cin >> k;
		L(i, 1, k) cin >> a[i];
		ll sum = 0;
		L(i, 1, k) sum += det(x[a[i]], y[a[i]], x[a[i % k + 1]], y[a[i % k + 1]]);
		if(sum > 0) reverse(a + 1, a + k + 1);
		int ns = k;
		L(i, 1, k) {
//			cout << a[i] << " " << a[(i + n - 2) % n + 1] << "\n";
			int l = e[mp[a[i]][a[i % k + 1]]].rk, r = e[mp[a[i]][a[(i + k - 2) % k + 1]]].rk;
//			swap(l, r);
//			cout << a[i] << " : " << l << " " << r << "\n";
			ns += pr[a[i]][r] - (l == 0 ? 0 : pr[a[i]][l - 1]);
			if(l > r) ns += all[a[i]];
//			cout << a[i] << " : " << ns << "\n";
		}
		cout << ns << "\n";
	}
	return 0;
}