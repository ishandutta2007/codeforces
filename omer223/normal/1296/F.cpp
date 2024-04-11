#define MOD 998244353
#define fast ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair
#define has(set, x) set.find(x) != set.end()
#define nohas(set, x) set.find(x) == set.end()
#define inc(mpp, x) {if(has(mpp, x)) mpp[x]++; else mpp.insert(mp(x,1));}
#define decc(mpp, x) {if(has(mpp, x)) {if(mpp[x] > 1) mpp[x]--; else mpp.erase(x);}}
#define F first
#define S second
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vvi vector<vi>
#define um unordered_map
#define us unordered_set
#include <iostream>
#include <list>
#include <queue>
#include <vector>
#include <map>
#include <string>
#include <unordered_map>
#include <iomanip>
#include <set>
#include <unordered_set>
#include <fstream>
#include <algorithm>
#include <chrono>
#include <stack>
#include <deque>
#include <queue>
#include <bitset>
#include <numeric>
using namespace std;
const int INF = 1 << 29;
typedef long long ll;
typedef unsigned long long ull;
inline int two(int n) { return 1 << n; }
ll extgcd(ll a, ll b, ll& x, ll& y) { if (b == 0) { x = 1; y = 0; return a; } else { int g = extgcd(b, a%b, y, x); y -= a / b * x; return g; } }
ll modpow(ll a, ll b) { ll res = 1; a %= MOD; for (; b; b >>= 1) { if (b & 1)res = res * a%MOD; a = a * a%MOD; }return res; }
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
struct que {
	int a, b, val;
	que() {
		a = 0;
		b = 0;
		val = 0;
	}
};
const int sz = 5e3 + 5;
vector<vector<int>> adj;
um<int, int> edge;
int father[sz], edgeVals[sz];
que queries[sz];
int n, m;
void dfs(int src, int fat) {
	father[src] = fat;
	for (auto x : adj[src]) {
		if (x == fat)continue;
		dfs(x, src);
	}
}
int main() {
	fast;
	ifstream in("input.txt");
	ofstream out("output.txt");
	cin >> n;
	int a, b;
	adj.resize(n);
	edgeVals[n - 1] = 1;
	foru(i, 0, n - 1) {
		cin >> a >> b;
		a--; b--;
		adj[a].pb(b);
		adj[b].pb(a);
		edge.insert(mp(a*n + b, i));
		edge.insert(mp(b*n + a, i));
		edgeVals[i] = 1;
	}
	dfs(0, -1);
	lca mylca(adj);
	cin >> m;
	bool bad = 0;
	foru(i, 0, m) {
		cin >> queries[i].a >> queries[i].b >> queries[i].val;
		a = queries[i].a - 1;
		b = queries[i].b - 1;
		int l = mylca.query(a, b);
		while (a != l) {
			int index = edge[a*n + father[a]];
			edgeVals[index] = max(edgeVals[index], queries[i].val);
			a = father[a];
		}
		while (b != l) {
			int index = edge[b*n + father[b]];
			edgeVals[index] = max(edgeVals[index], queries[i].val);
			b = father[b];
		}
	}
	foru(i, 0, m) {
		int mn = 1e9, a = queries[i].a - 1, b = queries[i].b - 1;
		int l = mylca.query(a, b);
		while (a != l) {
			mn = min(mn, edgeVals[edge[a*n + father[a]]]);
			a = father[a];
		}
		while (b != l) {
			mn = min(mn, edgeVals[edge[b*n + father[b]]]);
			b = father[b];
		}
		if (mn != queries[i].val) {
			bad = 1;
			break;
		}
	}
	if (bad) {
		cout << -1 << endl;
	}
	else {
		foru(i, 0, n - 1)cout << edgeVals[i] << " ";
	}
	return 0;
}