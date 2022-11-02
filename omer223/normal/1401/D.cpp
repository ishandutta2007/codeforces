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

const int sz = 1e5, md = 1e9 + 7;
int n, m;
vector<int> adj[sz];
ll primes[sz];
vector<ll> amts;
ll subt[sz];

void reset() {
	foru(i, 0, n) {
		adj[i].clear();
		subt[i] = 0;
	}
	amts.clear();
}

void dfs(int src, int prv) {
	subt[src] = 1;
	for (auto x : adj[src]) {
		if (x == prv)continue;
		dfs(x, src);
		subt[src] += subt[x];
	}
	for (auto x : adj[src]) {
		if (x == prv)continue;
		amts.pb(subt[x] * (n - subt[x]));
	}
}

void solve() {
	cin >> n;
	reset();
	int a, b;
	foru(i, 0, n - 1) {
		cin >> a >> b; a--; b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	dfs(0, -1);
	cin >> m;
	foru(i, 0, m)cin >> primes[i];
	sort(primes, primes + m);
	sort(amts.begin(), amts.end());
	ll tot = 0;
	if (m < n-1) {
		foru(i, 0, m) {
			tot += (primes[m - 1 - i] * amts[n - 2 - i]);
			tot %= md;
		}
		foru(i, m, n - 1) {
			tot += amts[n - 2 - i];
			tot %= md;
		}
		cout << tot<< endl;
	}
	else {
		ll rem = 1;
		foru(i, 0, m) {
			if (i < n - 2) {
				tot += (amts[i] * primes[i]);
				tot %= md;
			}
			else {
				rem *= primes[i];
				rem %= md;
			}
		}
		tot += rem * amts[n - 2];
		tot %= md;
		cout << tot << endl;
	}
}

int main() {
	fast;
	int t;
	cin >> t;
	while (t--)solve();

	return 0;
}