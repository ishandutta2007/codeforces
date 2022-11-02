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

list<int> adj[100000];
bool haveRoots[100000];
int father[100000];
ll deduct = 0;
bool hitOdd = false;
void dfsToMax(int src, int prev) {
	int rts = 0;
	bool rt = true;
	for (auto x : adj[src]) {
		if (x == prev) continue;
		rt = false;
		if (adj[x].size() == 1) rts++;
		else dfsToMax(x, src);
	}
	if (rts > 1) deduct += (rts - 1);
	if (rts > 0) haveRoots[src] = true;
	if (rt) father[src] = prev + 1;
}
void dfsToMin(int src, int prev, int dist) {
	if (adj[src].size() == 1 && prev != -1) { //root
		if (dist % 2 == 1) hitOdd = true;
		return;
	}
	for (auto x : adj[src]) {
		if (x == prev) continue;
		dfsToMin(x, src, dist + 1);
	}
}

int main() {
	fast;
	ifstream in("input.txt");
	ofstream out("output.txt");
	int a, b;
	ll n;
	cin >> n;
	FOR(i, n - 1) {
		cin >> a >> b; a--; b--;
		adj[a].pb(b); adj[b].pb(a);
	}
	int root = 0;
	while (root < n && adj[root].size() <= 1) root++;
	dfsToMax(root, -1);
	root = 0;
	while (root < n && adj[root].size() > 1) root++;
	dfsToMin(root, -1, 0);
	cout << (hitOdd == false ? 1 : 3) << " " << n - 1 - deduct << endl;
	return 0;
}