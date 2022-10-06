#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()

#define MAX_V 100010

int n, q;
vector<int> G[MAX_V];

int parent[18][MAX_V];
int depth[MAX_V];
int now;
int vs[200010];
int in[200010], out[200010];

void dfs(int v, int p, int d)
{
	parent[0][v] = p;
	depth[v] = d;
	vs[now] = v;
	in[v] = now++;
	for (int i = 0; i < G[v].size(); i++) {
		if (G[v][i] != p) {
			dfs(G[v][i], v, d + 1);
		}
	}
	vs[now] = v;
	out[v] = now++;	
}

void init(int V)
{
	dfs(0, -1, 0);
	for (int k = 0; k < 16; k++) {
		for (int v = 0; v < V; v++) {
			if (parent[k][v] < 0) parent[k+1][v] = -1;
			else parent[k+1][v] = parent[k][parent[k][v]];
		}
	}
}

int lca(int u, int v)
{
	if (depth[u] > depth[v]) swap(u, v);
	for (int k = 0; k < 17; k++){
		if (((depth[v] - depth[u]) >> k) & 1) {
			v = parent[k][v];
		}
	}

	if (u == v) return u;
	for (int k = 16; k >= 0; k--) {
		if (parent[k][u] != parent[k][v]) {
			u = parent[k][u];
			v = parent[k][v];
		}
	}
	return parent[0][u];
}

int tp[100010];
int f[100010];
int l[100010], r[100010];
int x[100010], y[100010];
int num[2][100010];
ll ans[100010];
ll cur;
int T[100010];

void add(int p) {
	int v = vs[p];
	//printf("ADD!! %d\n", v);
	if (T[v] == 0) {
		cur += num[tp[v]^1][f[v]];
		num[tp[v]][f[v]]++;
	} else {
		cur -= num[tp[v]^1][f[v]];
		num[tp[v]][f[v]]--;
	}
	T[v]++;
}

void del(int p) {
	int v = vs[p];
//	printf("DEL!! %d\n", v);	
	if (T[v] == 1) {
		cur -= num[tp[v]^1][f[v]];
		num[tp[v]][f[v]]--;
	} else {
		cur += num[tp[v]^1][f[v]];
		num[tp[v]][f[v]]++;		
	}
	T[v]--;	
}

int main() {
	scanf("%d", &n);
	rep(i, n) scanf("%d", &tp[i]);
	vi xs;

	rep(i, n) {
		scanf("%d", &f[i]);
		xs.pb(f[i]);
	}

	sort(ALL(xs));
	xs.erase(unique(ALL(xs)), xs.end());
	rep(i, n) f[i] = lower_bound(ALL(xs), f[i]) - xs.begin();

	rep(i, n - 1) {
		int a, b;
		scanf("%d %d", &a, &b); --a; --b;
		G[a].pb(b); G[b].pb(a);
	}

	init(n);

	scanf("%d", &q);

	rep(i, q) {
		int a, b;
		scanf("%d%d", &a, &b); --a; --b;
		int lc = lca(a, b);
		if (in[a] > in[b]) swap(a, b);
		x[i] = a, y[i] = b;
		if (a == lc) {
			l[i] = in[a];
			r[i] = in[b] + 1;
		} else {
			l[i] = out[a];
			r[i] = in[b] + 1;
		}
		//cout << "interval " << l[i] << " " << r[i] << endl;
	}
/*
	rep(i, now) {
		printf("now %d %d\n", i, vs[i]);
	}
*/
	int sq = sqrt(now);
	vector<int> qi(q);
	for (int i = 0; i < q; ++i) {
		qi[i] = i;
	}

	sort(qi.begin(), qi.end(), [&](int i, int j) { 
		if (l[i]/sq != l[j]/sq) return l[i] < l[j];
		return r[i] < r[j];
	});

	int nl = 0, nr = 0; // [nl,nr)
	for (int i : qi) {
		while (nl > l[i]) --nl, add(nl);
		while (nr < r[i]) add(nr), ++nr;
		while (nl < l[i]) del(nl), ++nl;
		while (nr > r[i]) --nr, del(nr);
		ans[i] = cur;
		int vv = lca(x[i], y[i]);
		/*
		puts("DEB");
		rep(j, xs.size()) {
			printf("%d %d\n", num[0][j], num[1][j]);
		}
		puts("END");*/
		if (vv != x[i]) {
			ans[i] += num[tp[vv]^1][f[vv]];
		}
	}

	rep(i, q) {
		printf("%I64d\n", ans[i]);
	}

	return 0;
}