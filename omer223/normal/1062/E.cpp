#define _CRT_SECURE_NO_WARNINGS
#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (ll i = k; i < n; i++)
#define ford(i, k, n) for (ll i = k; i >= n; i--)
#define pb push_back
#define ff first
#define ss second

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <unordered_map>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

struct lca {
	template<class T>
	struct rmq {
		vector<vector<T>> a;
		vector<int> logs;
		int dep, len;
		rmq(vector<T> arr) {
			len = arr.size();
			dep = 0;
			int tmp = len;
			while (tmp) {
				tmp >>= 1;
				dep++;
			}
			a.resize(dep);
			foru(i, 0, dep) {
				a[i].resize(len);
				for (int j = 0; j + (1 << i) <= len; j++) {
					if (!i)a[i][j] = arr[j];
					else a[i][j] = min(a[i - 1][j], a[i - 1][j + (1 << (i - 1))]);
				}
			}
			initLogs();
		}
		void initLogs() {
			logs.resize(len + 1);
			logs[1] = 0;
			foru(i, 2, len + 1)logs[i] = logs[i >> 1] + 1;
		}
		T query(int l, int r) {
			int mylen = logs[r - l + 1];
			return min(a[mylen][l], a[mylen][r - (1 << mylen) + 1]);
		}
	};
	vector<vector<int>> adj;
	vector<int> appear;
	vector<pii> dep;
	rmq<pii>* tree;
	int sz;
	lca(vector<vector<int>> adjacency) {
		adj = adjacency;
		sz = adjacency.size();
		appear.resize(sz);
		dfsscan(0, -1, 0);
		tree = new rmq<pii>(dep);
	}
	void dfsscan(int src, int prev, int currdep) {
		appear[src] = dep.size();
		dep.pb({ currdep, src });
		for (auto x : adj[src]) {
			if (x == prev)continue;
			dfsscan(x, src, currdep + 1);
			dep.pb({ currdep, src });
		}
	}
	int query(int a, int b) {
		int x = min(appear[a], appear[b]), y = max(appear[a], appear[b]);
		return tree->query(x, y).second;
	}
};
struct rangelca {
	vector<vector<int>> a;
	vector<int> logs;
	int dep, len;
	lca* mylca;
	rangelca(int n, lca* t) {
		mylca = t;
		len = n;
		dep = 0;
		int tmp = len;
		while (tmp) {
			tmp >>= 1;
			dep++;
		}
		a.resize(dep);
		a[0].resize(len);
		foru(j, 0, len)
			a[0][j] = j;
		foru(i, 1, dep) {
			a[i].resize(len);
			for (int j = 0; j + (1 << i) <= len; j++) {
				a[i][j] = mylca->query(a[i - 1][j], a[i - 1][j + (1 << (i - 1))]);
			}
		}
		initLogs();
	}
	void initLogs() {
		logs.resize(len + 1);
		logs[1] = 0;
		foru(i, 2, len + 1)logs[i] = logs[i >> 1] + 1;
	}
	int query(int l, int r) {
		int mylen = logs[r - l + 1];
		return mylca->query(a[mylen][l], a[mylen][r - (1 << mylen) + 1]);
	}
};

const int sz = 1e5;
int n;
vector<vector<int>> adj;
int f[sz];
rangelca* rlca;
lca* mylca;
int m;

void input() {
	cin >> n >> m;
	adj.resize(n);
	f[0] = -1;
	foru(i, 0, n - 1) {
		cin >> f[i + 1];
		adj[i + 1].pb(--f[i + 1]);
		adj[f[i + 1]].pb(i + 1);
	}
	mylca = new lca(adj);
	rlca = new rangelca(n, mylca);
}

int curlca;
int dep[sz];

pii foo(int l, int r) {
	if (r - l <= 2)
		return { l,r };
	int mid = (l + r) / 2;
	int l1 = rlca->query(l, mid), l2 = rlca->query(mid + 1, r);
	if ((l1 == curlca) == (l2 == curlca))
		return { -1,-1 };
	else if (l1 == curlca)
		return foo(l, mid);
	else
		return foo(mid + 1, r);
}

pii solve(int l, int r) {
	pii ret{ -1,-1 };
	curlca = rlca->query(l, r);
	if (curlca >= l && curlca <= r) 
		ret.ff = curlca;
	else {
		pii poten = foo(l, r);
		if (poten.ff == -1)
			ret.ff = l;
		else {
			int bstff = -1, bstdp = -1;
			for (int i = poten.ff; i <= poten.ss; i++) {
				ret.ff = i;
				if (ret.ff == l)
					ret.ss = dep[rlca->query(l + 1, r)];
				else if (ret.ff == r)
					ret.ss = dep[rlca->query(l, r - 1)];
				else
					ret.ss = dep[mylca->query(rlca->query(l, ret.ff - 1), rlca->query(ret.ff + 1, r))];
				if (bstdp < ret.ss) {
					bstdp = ret.ss;
					bstff = ret.ff;
				}
			}
			ret.ff = bstff;
			ret.ss = bstdp;
		}
	}
	if (ret.ff == l)
		ret.ss = dep[rlca->query(l + 1, r)];
	else if (ret.ff == r)
		ret.ss = dep[rlca->query(l, r - 1)];
	else
		ret.ss = dep[mylca->query(rlca->query(l, ret.ff - 1), rlca->query(ret.ff + 1, r))];
	return ret;
}

void dfs(int src, int prv) {
	for (int x : adj[src]) {
		if (x != prv) {
			dep[x] = dep[src] + 1;
			dfs(x, src);
		}
	}
}

int main() {
	fast;
	input();
	dfs(0, -1);
	while (m--) {
		int l, r;
		cin >> l >> r;
		pii sol = solve(--l, --r);
		cout << sol.ff + 1 << ' ' << sol.ss << '\n';
	}
	return 0;
}