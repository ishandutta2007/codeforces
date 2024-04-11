#define MOD 1000000007
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
#include <bitset>
using namespace std;
const int INF = 1 << 29;
typedef long long ll;
typedef unsigned long long ull;
inline int two(int n) { return 1 << n; }
ll extgcd(ll a, ll b, ll& x, ll& y) { if (b == 0) { x = 1; y = 0; return a; } else { int g = extgcd(b, a%b, y, x); y -= a / b * x; return g; } }
ll modpow(ll a, ll b) { ll res = 1; a %= MOD; for (; b; b >>= 1) { if (b & 1)res = res * a%MOD; a = a * a%MOD; }return res; }
struct custom_hash {
	static uint64_t splitmix64(uint64_t x) {
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}

	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}
};
const int sz = 1e5 + 5;
ll p[sz], h[sz], tre[sz], g[sz], b[sz];
list<int> adj[sz];
int n, m;

void reset() {
	foru(i, 0, n) {
		p[i] = 0;
		h[i] = 0;
		tre[i] = 0;
		b[i] = 0;
		g[i] = 0;
		adj[i].clear();
	}
}

void dfs(int src, int prev) {
	tre[src] = p[src];
	for (auto x : adj[src]) {
		if (x == prev)continue;
		dfs(x, src);
		tre[src] += tre[x];
	}
}

bool dfs2(int src, int prev) {
	if ((tre[src] + h[src]) % 2 == 1)return false;
	ll good = (tre[src] + h[src]) / 2, bad = good - h[src];
	if (good < 0 || bad < 0)return false;
	if (good > tre[src] || bad > tre[src])return false;
	g[src] = good;
	b[src] = bad;
	for (auto x : adj[src]) {
		if (x == prev)continue;
		if (!dfs2(x, src))return false;
	}
	return true;
}

bool dfs3(int src, int prev) {
	ll goods = 0;
	for (auto x : adj[src]) {
		if (x == prev)continue;
		if (!dfs3(x, src))return false;
		goods += g[x];
	}
	if (g[src] < goods)return false;
	return true;
}

void solve() {
	cin >> n >> m;
	reset();
	foru(i, 0, n)cin >> p[i];
	foru(i, 0, n)cin >> h[i];
	foru(i, 0, n - 1) {
		int a, b;
		cin >> a >> b; a--; b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	dfs(0, -1);
	if (!dfs2(0, -1)) {
		cout << "NO" << endl;
		return;
	}
	if (!dfs3(0, -1)) {
		cout << "NO" << endl;
		return;
	}
	cout << "YES" << endl;
}

int main() {
	fast;
	ifstream in("input.txt");
	ofstream out("output.txt");
	int t;
	cin >> t;
	while (t--)solve();
	return 0;
}