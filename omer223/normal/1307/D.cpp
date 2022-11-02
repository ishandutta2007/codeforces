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

list<int> adj[200005];
us<int> special;
int n, m, k;
int srcdest[200005], destsrc[200005];
vector<pair<pii, int>> specialFromTo;
bitset<200005> vis;

void bfs(int src, int arr[]) {
	queue<pii> q;
	arr[src] = 0;
	vis.reset();
	vis[src] = 1;
	q.push(mp(src, 0));
	while (!q.empty()) {
		pii x = q.front(); q.pop();
		for (auto y : adj[x.first]) {
			if (!vis[y]) {
				vis[y] = 1;
				arr[y] = x.second + 1;
				q.push(mp(y, arr[y]));
			}
		}
	}
}

int main() {
	fast;
	ifstream in("input.txt");
	ofstream out("output.txt");
	int tmp, a, b;
	bool flag = false;
	cin >> n >> m >> k;
	foru(i, 0, k) {
		cin >> tmp; tmp--;
		special.insert(tmp);
	}
	foru(i, 0, m) {
		cin >> a >> b; a--; b--;
		adj[a].pb(b); adj[b].pb(a);
		if (has(special, a) && has(special, b)) flag = true;
	}
	bfs(0, srcdest);
	bfs(n - 1, destsrc);
	if (flag) {
		cout << srcdest[n - 1] << endl;
		return 0;
	}
	for (auto x : special) 
		specialFromTo.pb(mp(mp(srcdest[x], destsrc[x]), x));
	sort(specialFromTo.begin(), specialFromTo.end());
	int maxWithAdd = 0, mx;
	ford(i, k - 1, 0) {
		if (i == k - 1) {
			mx = specialFromTo[i].first.second;
			continue;
		}
		maxWithAdd = max(maxWithAdd, specialFromTo[i].first.first + mx + 1);
		mx = max(mx, specialFromTo[i].first.second);
	}
	cout << min(maxWithAdd, srcdest[n - 1]) << endl;
	return 0;
}