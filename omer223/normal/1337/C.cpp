#define MOD 1000000007
#define fast ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define FOR(i, n) for (int i = 0; i < n; i++)
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
using namespace std;
const int INF = 1 << 29;
typedef long long ll;
typedef unsigned long long ull;
inline int two(int n) { return 1 << n; }
ll extgcd(ll a, ll b, ll& x, ll& y) { if (b == 0) { x = 1; y = 0; return a; } else { int g = extgcd(b, a%b, y, x); y -= a / b * x; return g; } }
ll modpow(ll a, ll b) { ll res = 1; a %= MOD; for (; b; b >>= 1) { if (b & 1)res = res * a%MOD; a = a * a%MOD; }return res; }

list<ll> adj[200000];
ll howManyBlock[200000];
ll dist[200000];
ll father[200000];
us<ll> ind;

ll dfs(ll src, ll prev) {
	bool root = true;
	father[src] = prev;
	for (auto x : adj[src]) {
		if (x == prev) continue;
		root = false;
		dist[x] = 1 + dist[src];
		howManyBlock[src] += dfs(x, src) + 1;
	}
	return howManyBlock[src];
}
void popSons(ll src, ll prev) {
	for (auto x : adj[src]) {
		if (x == prev)continue;
		popSons(x, src);
	}
	ind.erase(src);
}

int main() {
	fast;
	ifstream in("input.txt");
	ofstream out("output.txt");
	ll n, k, u, v;
	cin >> n >> k;
	FOR(i, n - 1) {
		cin >> u >> v; u--; v--;
		adj[u].pb(v); adj[v].pb(u);
	}
	dfs(0, -1);
	priority_queue<pair<ll, ll>> worth;
	for (ll i = 1; i < n; i++) {
		worth.push(mp(dist[i] - howManyBlock[i], i));
	}
	ll res = 0;
	while (k--) {
		auto x = worth.top();
		ll l = x.first;
		worth.pop();
		res += l;
	}
	cout << res << endl;
	return 0;
}