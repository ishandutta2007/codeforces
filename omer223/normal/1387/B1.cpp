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

const int sz = 1e5 + 1;
list<int> adj[sz];
int n, deg[sz], vil[sz], ans = 0, lst = -1;
us<int> rts;
bitset<sz> mark;

void input() {
	cin >> n;
	int a, b;
	foru(i, 0, n - 1) {
		cin >> a >> b; a--; b--;
		adj[a].pb(b);
		adj[b].pb(a);
		deg[a]++;
		deg[b]++;
	}
	foru(i, 0, n) {
		if (deg[i] == 1)rts.insert(i);
		vil[i] = i;
	}
}

void dfs(int src) {
	mark[src] = 1;
	deg[src] = 0;
	rts.erase(src);
	lst = src;
	int to = -1;
	for (auto x : adj[src]) {
		if (mark[x])continue;
		deg[x]--;
		if (vil[src] == src) {
			to = vil[src];
			vil[src] = vil[x];
			vil[x] = to;
			ans += 2;
		}
		if (deg[x] == 1) dfs(x);
	}
}

int main() {
	fast;
	input();
	while (!rts.empty()) {
		int k = *rts.begin();
		dfs(k);
	}
	if (vil[lst] == lst) {
		int tmp = vil[lst];
		vil[lst] = vil[*adj[lst].begin()];
		vil[*adj[lst].begin()] = tmp;
		ans += 2;
	}
	cout << ans << endl;
	foru(i, 0, n)cout << vil[i] + 1 << " ";
	cout << endl;
	return 0;
}