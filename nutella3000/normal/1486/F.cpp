#include <bits/stdc++.h>
       
using namespace std;
       
       
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
       
//#define GCC optimize("O3, Ofast")
//#define GCC optimize("unroll-loops")
#define aidar asadulin
        
#define int long long
#define ull long long
#define ll long long
#define mp make_pair
#define pii pair<int, int>
#define pip pair<int, pii>
#define fi first
#define se second
#define all(_v) _v.begin(), _v.end()
#define sz(a) (int) (a.size())
#define chkmax(a, b) a = max(a, b)
#define chkmin(a, b) a = min(a, b)
#define ld double
       
const int inf = 1e9 + 7;
const int max_n = 3e5 + 3, log_n = 20;

int n;
vector<int> gr[max_n];
int tin[max_n], tout[max_n], T = 0;
int par[max_n][log_n];

void build_dfs(int v, int pr) {
	tin[v] = T++;
	for(int to : gr[v]) {
		if (to != pr) {
			par[to][0] = v;
			for(int i = 1;i < log_n;i++)
				par[to][i] = par[par[to][i - 1]][i - 1];
			build_dfs(to, v);
		}
	}
	tout[v] = T++;
}

bool ispar(int v1, int v2) {
	return tin[v1] <= tin[v2] && tout[v1] >= tout[v2];
}

pii find_lca(int v1, int v2) {
	for(int k = log_n - 1;k >= 0;k--) {
		if (!ispar(par[v1][k], v2)) v1 = par[v1][k];
		//if (k == 1) cout << "fi " << v1 + 1 << " " << v2 + 1 << " " << par[v2][1] << endl;
		if (!ispar(par[v2][k], v1)) v2 = par[v2][k];
	}
	//cout << "find_lca " << v1 + 1 << " " << v2 + 1 << " " << ispar(par[v2][0], v1) << endl;
	return {v1, v2};
}

vector<int> starts[max_n];
pii pth[max_n];

set<int> a[max_n];
int lca_c[max_n], all_c[max_n];

int res = 0;

void dfs(int v, int pr) {

	set<int> ch;
	vector<pii> upd;


	for(int to : gr[v]) {
		if (to == pr) continue;
		ch.emplace(to);
		dfs(to, v);

		if (sz(a[v]) < sz(a[to])) swap(a[v], a[to]);

		for(int i : a[to]) {
			if (a[v].count(i)) {
				upd.emplace_back(find_lca(pth[i].fi, pth[i].se));
				//cout << i << " " << pth[i].fi << " " << pth[i].se << endl;
				a[v].erase(i);
				lca_c[v]++;
			}else {
				a[v].emplace(i);
			}
		}
	}

	for(int i : starts[v]) {
		if (a[v].count(i)) {
			upd.emplace_back(find_lca(pth[i].fi, pth[i].se));
			//cout << i << " " << pth[i].fi << " " << pth[i].se << endl;
			a[v].erase(i);
			lca_c[v]++;
		}else {
			a[v].emplace(i);
		}
	}

	all_c[v] = sz(a[v]) + lca_c[v];

	//cout << v + 1 << " " << all_c[v] << " " << lca_c[v] << endl;

	map<pii, int> r;
	//cout << " sz upd " << sz(upd) << endl;
	for(auto i : upd) {
		if (i.fi > i.se) swap(i.fi, i.se);
		r[i]++;
		//cout << i.fi + 1 << " " << i.se + 1 << " " << r[i] << endl;
	}

	/*cout << "r:";
	for(auto i : r)
		cout << i.fi.fi + 1 << " " << i.fi.se + 1 << " " << i.se << endl;
	cout << endl;*/

	for(auto i : upd) {
		if (i.fi > i.se) swap(i.fi, i.se);
		res += all_c[v] - 1;
		all_c[v]--; lca_c[v]--;

		if (ch.count(i.fi)) {
			res -= (all_c[i.fi] - lca_c[i.fi]) - 1;
			all_c[i.fi]--;
		}

		//cout << "res " << res << endl;
		if (ch.count(i.se)) {
			res -= (all_c[i.se] - lca_c[i.se]) - 1;
			all_c[i.se]--;
		}

		if (ch.count(i.fi) && ch.count(i.se)) {
			res += r[i] - 1;
			r[i]--;
		}
		//cout << "upd " << i.fi + 1 << " " << i.se + 1 << " " << res << " " << r[i] << endl;
	}
}

void solve() {
	cin >> n;
	for(int i = 0;i < n - 1;i++) {
		int v1, v2;
		cin >> v1 >> v2;
		gr[--v1].emplace_back(--v2);
		gr[v2].emplace_back(v1);
	}

	int m;
	cin >> m;
	for(int i = 0;i < m;i++) {
		int v1, v2;
		cin >> v1 >> v2;
		v1--; v2--;
		pth[i] = {v1, v2};
		starts[v1].emplace_back(i);
		starts[v2].emplace_back(i);
	}

	build_dfs(0, -1);

	//cout << "pre" << endl;
	dfs(0, -1);

	cout << res << endl;
}


signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);

    solve();
}