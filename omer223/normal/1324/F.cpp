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

int colors[200000], tmpAns[200000], tmpUp[200000], realAns[200000];
list<int> adj[200000];

int dfs(int src, int prev) {
	//thats not the same code
	int sum = 0;
	bool root = true;
	for (auto x : adj[src]) {
		if (x != prev) {
			int t = dfs(x, src);
			if (t > 0) {
				sum += t;
			}
			root = false;
		}
	}
	if (root) {
		if (colors[src] == 1) {
			tmpAns[src] = 1; return 1;
		}
		else {
			tmpAns[src] = -1;  return -1;
		}
	}
	if (colors[src] == 1) sum++;
	else sum--;
	tmpAns[src] = sum;
	return sum;
}

void dfs2(int src, int prev) {
	realAns[src] = tmpAns[src] + tmpUp[src];
	for (auto x : adj[src]) {
		if (x == prev) continue;
		if (tmpAns[x] > 0) tmpUp[x] = max(0, realAns[src] - tmpAns[x]);
		else tmpUp[x] = max(0, realAns[src]);
		dfs2(x, src);
	}
}

int main() {
	fast;
	ifstream in("input.txt");
	ofstream out("output.txt");
	int n, a, b;
	cin >> n;
	FOR(i, n) cin >> colors[i];
	FOR(i, n - 1) {
		cin >> a >> b; a--; b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	realAns[0] = dfs(0, 0);
	dfs2(0, 0);
	FOR(i, n) cout << realAns[i] << " ";
	return 0;
}