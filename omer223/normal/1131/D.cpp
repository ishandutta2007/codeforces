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

const int sz = 1e3 + 5;
char a[sz][sz];
int n, m;
struct DisjointSet {
	us<int> fathers;
	vi f, sz;
	DisjointSet(int size) {
		f.resize(size);
		sz.resize(size);
		foru(i, 0, size) {
			f[i] = i;
			sz[i] = i;
			fathers.insert(i);
		}
	}
	int father(int src) {
		while (src != f[src])src = f[src];
		return src;
	}
	bool unite(int a, int b) {
		int fa = father(a), fb = father(b);
		if (sz[fa] < sz[fb])swap(fa, fb);
		if (fa == fb)return false;
		f[fb] = fa;
		fathers.erase(fb);
		sz[fa] = max(sz[fa], sz[fb] + 1);
		return true;
	}
};
um<int, int> mem, memr;
vector<vector<int>> adj;
vector<int> sorted;
vector<int> indeg;
int szsz;
bool topoSort() {
	sorted.resize(szsz);
	queue<pii> q;
	indeg.resize(szsz);
	foru(i, 0, szsz)indeg[i] = 0;
	foru(i, 0, szsz) {
		for (auto x : adj[i])indeg[x]++;
	}
	foru(i, 0, szsz) {
		if (!indeg[i]) {
			q.push(mp(i, 1));
			sorted[i] = 1;
		}
	}
	while (!q.empty()) {
		pii x = q.front(); q.pop();
		for (auto y : adj[x.first]) {
			indeg[y]--;
			if (!indeg[y]) {
				sorted[y] = x.second + 1;
				q.push(mp(y, sorted[y]));
			}
		}
	}
	foru(i, 0, szsz) {
		if (!sorted[i])return false;
	}
	return true;
}
int main() {
	fast;
	ifstream in("input.txt");
	ofstream out("output.txt");
	cin >> n >> m;
	DisjointSet d(n + m);
	string s;
	foru(i, 0, n) {
		cin >> s;
		foru(j, 0, m) {
			a[i][j] = s[j];
			if (a[i][j] == '=')d.unite(i, j + n);
		}
	}
	int cr = 0;
	szsz = d.fathers.size();
	for (auto x : d.fathers) {
		mem[x] = cr;
		memr[cr] = x;
		cr++;
	}
	adj.resize(cr);
	foru(i, 0, n) {
		foru(j, 0, m) {
			if (a[i][j] == '<') {
				int fi = mem[d.father(i)], fj = mem[d.father(j+n)];
				if (fi == fj) {
					cout << "No" << endl;
					return 0;
				}
				adj[fi].pb(fj);
			}
			else if (a[i][j] == '>') {
				int fi = mem[d.father(i)], fj = mem[d.father(j+n)];
				if (fi == fj) {
					cout << "No" << endl;
					return 0;
				}
				adj[fj].pb(fi);
			}
		}
	}
	if (!topoSort()) {
		cout << "No" << endl;
		return 0;
	}
	cout << "Yes" << endl;
	foru(i, 0, n)cout << sorted[mem[d.father(i)]] << " ";
	cout << endl;
	foru(i, 0, m)cout << sorted[mem[d.father(i + n)]] << " ";
	return 0;
}