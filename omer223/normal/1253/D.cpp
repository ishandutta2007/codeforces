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
#include <bitset>
#include <numeric>
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

list<int> adj[200000];
int f[200000], sz[200000];
pii mm[200000];
us<int> rem, fs;

int father(int src) {
	if (f[src] == src) return src;
	else return father(f[src]);
}

bool unite(int a, int b) {
	int fa = father(a), fb = father(b);
	if (fa == fb) return false;
	if (sz[fa] < sz[fb]) swap(fb, fa);
	f[fb] = fa;
	fs.erase(fb);
	sz[fa] = max(sz[fa], sz[fb] + 1);
	mm[fa].first = min(mm[fa].first, mm[fb].first);
	mm[fa].second = max(mm[fa].second, mm[fb].second);
	return true;
}

void dfs(int src, int prev) {
	if (prev != -1) {
		unite(src, prev);
	}
	rem.erase(src);
	for (auto x : adj[src]) {
		if (rem.find(x) != rem.end()) dfs(x, src);
	}
}

int main() {
	fast;
	ifstream in("input.txt");
	ofstream out("output.txt");
	ll n, m, a, b;
	cin >> n >> m;
	foru(i, 0, m) {
		cin >> a >> b; a--; b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	foru(i, 0, n) {
		rem.insert(i);
		f[i] = i;
		mm[i].first = i;
		mm[i].second = i;
		fs.insert(i);
	}
	while (!rem.empty()) {
		auto x = rem.begin();
		dfs(*x, -1);
	}
	int total = 0;
	int l = 0, r = 0, tmpf, mn, mx;
	while (l < n) {
		tmpf = father(l);
		mn = mm[tmpf].first;
		mx = mm[tmpf].second;
		foru(i, mn, mx + 1) {
			if (father(i) != tmpf) {
				total++;
				unite(l, i);
				tmpf = father(l);
				mx = max(mx, mm[tmpf].second);
			}
		}
		l = mx + 1;
	}
	cout << total << endl;
	return 0;
}