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

ifstream in("input.txt");
ofstream out("outbad.txt");

const int sz = 1e5 + 5;
list<int> adj[sz];
int n = 0, st[sz], vil[sz], centroid = -1, ft[sz];
ll ans = 0;
bool calc = 1;
vector<int> v;
bitset<sz> mark;

void reset() {
	mark.reset();
	calc = 1;
	v.clear();
	ans = 0;
	foru(i, 0, n) {
		adj[i].clear();
		st[i] = 0;
		vil[i] = 0;
		ft[i] = 0;
	}
	centroid = -1;
}

void dfs(int src, int prev) {
	ft[src] = prev;
	st[src] = 1;
	for (auto x : adj[src]) {
		if (x == prev)continue;
		dfs(x, src);
		st[src] += st[x];
	}
	if (calc) {
		for (auto x : adj[src]) {
			if (x == prev)continue;
			ans += 2 * min(st[x], n - st[x]);
		}
	}
}

void input() {
	cin >> n;
	int a, b;
	foru(i, 0, n - 1) {
		cin >> a >> b; a--; b--;
		adj[a].pb(b);
		adj[b].pb(a);
		vil[i] = i;
	}
	vil[n - 1] = n - 1;
}

void findCentroid() {
	bool bad = 0;
	foru(i, 0, n) {
		if (2 * (n - st[i]) > n)continue;
		bad = 0;
		for (auto x : adj[i]) {
			if (x == ft[i])continue;
			if (2 * st[x] > n) {
				bad = 1;
				break;
			}
		}
		if (bad)continue;
		centroid = i;
		break;
	}
}
void dfs2(int src, int prev) {
	v.pb(src);
	for (auto x : adj[src]) {
		if (x == prev)continue;
		dfs2(x, src);
	}
}

int main() {
	fast;
	int t;
	//in >> t;
	t = 1;
	while (t--) {
		//reset();
		input();
		dfs(0, -1);
		cout << ans << endl;
		findCentroid();
		calc = 0;
		dfs(centroid, -1);
		int mxs = -1;
		for (auto x : adj[centroid]) {
			if (st[x] > mxs) {
				mxs = st[x];
			}
		}
		vi vv;
		vv.pb(centroid);
		for (auto x : adj[centroid]) {
			if (st[x] == mxs) {
				vv.pb(x); mark[x] = 1;
			}
		}
		int vvsz = vv.size();
		for (int i = 0; i < vvsz; i++)vil[vv[i]] = vv[(i + 1) % vvsz];
		mxs--;
		for (auto x : adj[centroid]) {
			if (mark[x]) {
				for (auto y : adj[x]) {
					if (y == centroid)continue;
					dfs2(y, x);
				}
			}
			else dfs2(x, centroid);
		}
		int vsz = v.size();
		for (int i = 0; i < vsz; i++) {
			vil[v[i]] = v[(i + mxs) % vsz];
		}
		foru(i, 0, n)cout << vil[i] + 1 << " ";
		cout << endl;
	}
	return 0;
}