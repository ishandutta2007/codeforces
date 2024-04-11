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
const int sz = 1e5;
int n, m, a, b, c, deg[sz];
list<pair<pii, int>> adj[sz];
vector<int> tmp;

bool topo(int cost) {
	queue<int> zeros;
	vector<pair<pii, int>> excluded;
	vector<int> order, ind(n,0);
	tmp.clear();
	foru(i, 0, n)deg[i] = 0;
	foru(i, 0, n) {
		for (auto x : adj[i]) {
			if (x.first.second > cost)deg[x.first.first]++;
			else excluded.pb(mp(mp(i,x.first.first),x.second));
		}
	}
	foru(i, 0, n) {
		if (!deg[i])zeros.push(i);
	}
	while (!zeros.empty()) {
		int x = zeros.front(); zeros.pop();
		order.pb(x);
		for (auto y : adj[x]) {
			if (y.first.second > cost) {
				deg[y.first.first]--;
				if (!deg[y.first.first])zeros.push(y.first.first);
			}
		}
	}
	if (order.size() < n)return false;
	foru(i, 0, n)ind[order[i]] = i;
	for (auto p : excluded) {
		if (ind[p.first.first] > ind[p.first.second])tmp.pb(p.second);
	}
	return true;
}

int main() {
	fast;
	ifstream in("input.txt");
	ofstream out("output.txt");
	cin >> n >> m;
	foru(i, 0, m) {
		cin >> a >> b >> c; a--; b--;
		adj[a].pb(mp(mp(b, c),i+1));
	}
	int l = 1, r = 1e9+1, mid, bst = -1;
	vector<int> bestadder;
	while (l <= r) {
		mid = (l + r + 1) / 2;
		int actual = mid - 1;
		if (topo(actual)) {
			bestadder = tmp;
			bst = actual;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	cout << bst << " " << bestadder.size() << endl;
	for (int x : bestadder)cout <<x << " ";
	return 0;
}