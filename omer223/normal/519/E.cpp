#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <bitset>
#include <numeric>
#include <set>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<ll, ll> pll;
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
struct lca {
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
		dep.pb(mp(currdep, src));
		for (auto x : adj[src]) {
			if (x == prev)continue;
			dfsscan(x, src, currdep + 1);
			dep.pb(mp(currdep, src));
		}
	}
	int query(int a, int b) {
		int x = min(appear[a], appear[b]), y = max(appear[a], appear[b]);
		return tree->query(x, y).second;
	}
};

const int sz = 2e5 + 5, lsz = 20;
int n, m;
vector<vector<int>> adj;
int dep[sz], subt[sz], f[sz], lft[lsz][sz];

void initLift() {
	foru(j, 0, n)lft[0][j] = f[j];
	foru(i, 1, lsz) {
		foru(j, 0, n) {
			lft[i][j] = lft[i - 1][j];
			if (lft[i][j] == -1)continue;
			lft[i][j] = lft[i - 1][lft[i][j]];
		}
	}
}

void dfs(int src, int prv) {
	f[src] = prv;//CHECK ZERO
	subt[src] = 1;
	for (auto x : adj[src]) {
		if (x == prv)continue;
		dep[x] = dep[src] + 1;
		dfs(x, src);
		subt[src] += subt[x];
	}
}

lca* mylca;

inline int lift(int a, int up) {
	foru(i, 0, lsz) {
		if ((up >> i) & 1) {
			a = lft[i][a];
			if (a == -1)return -1;
		}
	}
	return a;
}

inline int dist(int a, int b) {
	return dep[a] + dep[b] - 2 * dep[mylca->query(a, b)];
}

void solve() {
	int a, b;
	cin >> a >> b; a--; b--;
	if (a == b) {
		cout << n << endl;
		return;
	}
	int l = mylca->query(a, b), d = dist(a, b);
	if (d & 1) {
		cout << 0 << endl;
		return;
	}
	if (dep[a] < dep[b])swap(a, b);
	int beforeA = lift(a, (d >> 1) - 1), beforeB = lift(b, (d >> 1) - 1),ret = n, lifted = f[beforeA];
	ret -= subt[beforeA];
	if (dep[a] == dep[b]) ret -= subt[beforeB];
	else ret -= (n - subt[lifted]);
	cout << ret << endl;
}

int main() {
	fast;
	cin >> n;
	adj.resize(n);
	foru(i, 0, n - 1) {
		int a, b;
		cin >> a >> b;
		adj[--a].pb(--b);
		adj[b].pb(a);
	}
	dfs(0, -1);
	initLift();
	mylca = new lca(adj);
	cin >> m;
	while (m--)solve();
	return 0;
}