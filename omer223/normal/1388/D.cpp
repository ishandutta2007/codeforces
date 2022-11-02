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

const int sz = 2e5 + 5;
int n;
ll a[sz],ta[sz], b[sz], indeg[sz];
list<int> adj[sz], radj[sz];
us<int> uv, heads;
vector<int> ord, remain;
ll ans = 0;

void dfs(int src, int prv) {
	heads.erase(src);
	ll tot = 0, tmp;
	for (auto x : radj[src]) {
		if (x == prv)continue;
		dfs(x, src);
		tmp = ta[x];
		if (tmp >= 0) {
			ord.pb(x);
			ta[src] += tmp;
		}
		else remain.pb(x);
	}
}

int main() {
	fast;
	cin >> n;
	foru(i, 0, n) {
		cin >> a[i];
		ta[i] = a[i];
	}
	foru(i, 0, n) {
		uv.insert(i);
		cin >> b[i];
		b[i]--;
		if (b[i] != -2) {
			adj[i].pb(b[i]);
			radj[b[i]].pb(i);
			indeg[i]++;
		}
	}
	foru(i, 0, n) {
		if (!indeg[i])heads.insert(i);
	}
	while (!heads.empty()) {
		auto x = heads.begin();
		int v = *x;
		dfs(*x, -1);
		ord.pb(v);
	}
	vector<int> res;
	for (int k : ord)res.pb(k);
	reverse(remain.begin(), remain.end());
	for (int k : remain)res.pb(k);
	ll ans = 0;
	for (int i : res) {
		ans += a[i];
		if (b[i] >= 0)a[b[i]] += a[i];
	}
	cout << ans << endl;
	for (int i : res)cout << i + 1 << " ";
	return 0;
}