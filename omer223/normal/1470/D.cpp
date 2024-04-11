
#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define ff first
#define ss second

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int sz = 4e5;
int n, m;
vector<int> adj[sz], tadj[sz], badj[sz];
int dep[sz];
bitset<sz> bs, vis, cant;

void reset() {
	foru(i, 0, n) {
		adj[i].clear();
		tadj[i].clear();
		badj[i].clear();
		dep[i] = 0;
		bs[i] = 0;
		vis[i] = 0;
		cant[i] = 0;
	}
}

void dfs1(int src) {
	vis[src] = 1;
	for (int x : adj[src]) {
		if (!vis[x]) {
			dep[x] = dep[src] + 1;
			tadj[src].pb(x);
			dfs1(x);
		}
		else {
			if (dep[x] > dep[src])badj[src].pb(x);
		}
	}
}

void dfs2(int src) {
	if (!cant[src]) {
		bs[src] = 1;
		for (int x : adj[src])cant[x] = 1;
	}
	for (int x : tadj[src]) dfs2(x);
}


void solve() {
	cin >> n >> m;
	reset();
	foru(i, 0, m) {
		int x, y;
		cin >> x >> y;
		adj[--x].pb(--y);
		adj[y].pb(x);
	}
	dfs1(0);
	foru(i, 0, n) {
		if (!vis[i]) {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
	dfs2(0);
	int cnt = 0;
	foru(i, 0, n)cnt += bs[i];
	cout << cnt << '\n';
	foru(i, 0, n) {
		if (bs[i])cout << i + 1 << ' ';
	}
	cout << '\n';
}


int main() {
	fast;
	int t;
	cin >> t;
	while (t--)solve();

	return 0;
}