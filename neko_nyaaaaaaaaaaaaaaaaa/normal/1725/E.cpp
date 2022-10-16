#include <bits/stdc++.h>
using namespace std;

#define int long long

const int M = 998244353;
const int MAXN = 200005;

int sieve[MAXN+1], pr[MAXN+1];

void init() {
	for (int i = 2; i <= MAXN; i++) {
		if (!sieve[i]) {
			pr[i] = i;
			for (int j = i*2; j <= MAXN; j += i) {
				sieve[j] = 1;
				pr[j] = i;
			}
		}
	}
}

vector<int> factorize(int x) {
	vector<int> ans;
	while (x > 1) {
		int y = pr[x];
		ans.push_back(y);
		while ((x % y) == 0) x /= y;
	}
	return ans;
}

int n, t, a[MAXN], par[MAXN], height[MAXN], in[MAXN], out[MAXN];
vector<int> adj[MAXN];

void dfs(int now, int prv) {
	in[now] = t; t++;
	par[now] = prv;
	height[now] = height[prv] + 1;
	for (auto u: adj[now]) {
		if (u != prv) dfs(u, now);
	}
	out[now] = t;
}

int sp[MAXN][20];

void LCA_init() {
	for (int i = 1; i <= n; i++) {
		sp[i][0] = par[i];
	}
	for (int j = 1; j < 20; j++) {
		for (int i = 1; i <= n; i++) {
			sp[i][j] = sp[sp[i][j-1]][j-1];
		}
	}
}

int LCA(int u, int v) {
	if (height[u] < height[v]) swap(u, v);

	int dif = height[u] - height[v];
	for (int i = 19; i >= 0; i--) {
		if (dif & (1 << i)) {
			u = sp[u][i];
		}
	}
	if (u == v) return u;

	for (int i = 19; i >= 0; i--) {
		if (sp[u][i] != sp[v][i]) {
			u = sp[u][i];
			v = sp[v][i];
		}
	}
	return sp[u][0];
}

int dist(int u, int v) {
	return height[u] + height[v] - 2*height[LCA(u, v)];
}

bool cmp(int u, int v) {
	return in[u] < in[v];
}

int rev[MAXN];

vector<pair<int, int>> compress(vector<int> vt) {
	sort(vt.begin(), vt.end(), cmp);

	int m = vt.size();
	for (int i = 0; i+1 < m; i++) {
		vt.push_back(LCA(vt[i], vt[i+1]));
	}
	sort(vt.begin(), vt.end(), cmp);
	vt.erase(unique(vt.begin(), vt.end()), vt.end());

	for (int i = 0; i < vt.size(); i++) {
		rev[vt[i]] = i;
	}
	vector<pair<int, int>> edges = {{vt[0], vt[0]}};
	for (int i = 0; i < vt.size() - 1; i++) {
		int a = vt[i], b = vt[i+1];
		edges.emplace_back(vt[rev[LCA(a, b)]], b);
	}
	return edges;
}

int val[MAXN], subtr[MAXN], tots;
vector<pair<int, int>> adj2[MAXN];

void dfs2(int now, int prv) {
	subtr[now] = val[now];
	for (auto [u, w]: adj2[now]) {
		if (u != prv) {
			dfs2(u, now);
			subtr[now] += subtr[u];
		}
	}
} 

void dfs3(int now, int prv, int &ans) {
	for (auto [u, w]: adj2[now]) {
		if (u != prv) {
			dfs3(u, now, ans);
			
			int fi = subtr[u];
			int se = tots - fi;

			//cout << u << ' ' << fi << ' ' << se << endl;

			int ffs = fi*(fi-1)/2 % M;
			ffs = ffs*se % M;

			int fss = se*(se-1)/2 % M;
			fss = fss*fi % M;

			ans = (ans + fss*w) % M;
			ans = (ans + ffs*w) % M;
		}
	}
} 

int solve(vector<int> vt) {
	if (vt.size() <= 2) return 0;
	//cout << "VT ";
	//for (int i: vt) cout << i << ' ';
		//cout << '\n';

	vector<pair<int, int>> edges = compress(vt);
	for (auto [u, v]: edges) {
		if (u == v) continue;
		int w = dist(u, v);

		//cout << "ED " << u << ' ' << v << '\n';
		
		adj2[u].emplace_back(v, w);
		adj2[v].emplace_back(u, w);
	}
	for (int i: vt) val[i] = 1;

	tots = vt.size();
	int ans = 0;
	dfs2(vt[0], vt[0]);
	dfs3(vt[0], vt[0], ans);

	for (auto [u, v]: edges) {
		adj2[u].clear(); val[u] = subtr[u] = 0;
		adj2[v].clear(); val[v] = subtr[v] = 0;
	}

	return ans;
}

vector<int> vrt[MAXN];

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	init();	

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1, 0);
	LCA_init();

	for (int i = 1; i <= n; i++) {
		vector<int> prs = factorize(a[i]);
		for (int j: prs) {
			vrt[j].push_back(i);
		}
	}

	int ans = 0;
	for (int i = 1; i <= MAXN; i++) {
		if (vrt[i].empty()) continue;

		int tmp = solve(vrt[i]);
		//cout << i << ' ' << vrt[i].size() << ' ' << tmp << endl;
		ans = (ans + tmp) % M;
	}
	cout << ans << '\n';

	return 0;
}