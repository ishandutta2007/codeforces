#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int sz = 3e5;
vector<int> adj[sz];
int n, subt[sz], mxSon[sz];
pii rndPair, rem;

void input() {
	cin >> n;
	foru(i, 0, n) {
		adj[i].clear(); subt[i] = 0; mxSon[i] = 1e9;
	}
	int a, b;
	foru(i, 0, n - 1) {
		cin >> a >> b; a--; b--;
		if (!i)rndPair = mp(a + 1, b + 1);
		adj[a].pb(b);
		adj[b].pb(a);
	}
}

void dfs1(int src, int prv) {
	subt[src] = 1;
	for (auto x : adj[src]) {
		if (x == prv)continue;
		dfs1(x, src);
		subt[src] += subt[x];
	}
}

void dfs2(int src, int prv) {
	int sm = 0, mx = 0;
	for (auto x : adj[src]) {
		if (x == prv)continue;
		mx = max(mx, subt[x]);
		sm += subt[x];
		dfs2(x, src);
	}
	mxSon[src] = max(mx, n - sm - 1);
}

void dfs3(int src, int prv) {
	bool leaf = 1;
	for (auto x : adj[src]) {
		if (x == prv)continue;
		else {
			leaf = 0;
			dfs3(x, src);
			break;
		}
	}
	if (leaf) {
		rem = mp(src+1, prv+1);
		return;
	}
}

void solve() {
	input();
	dfs1(0, -1);
	dfs2(0, -1);
	int mn = 1e9, b1 = -1, b2 = -1;
	for (int i = 0; i < n; i++) {
		if (mxSon[i] < mn) {
			mn = mxSon[i];
			b2 = -1;
			b1 = i;
		}
		else if (mxSon[i] == mn) {
			b2 = i;
		}
	}
	if (b2 == -1) {
		cout << rndPair.first << " " << rndPair.second << endl;
		cout << rndPair.first << " " << rndPair.second << endl;
	}
	else {
		dfs3(b1, b2);
		cout << rem.first << " " << rem.second << endl;
		cout << rem.first << " " << b2 + 1 << endl;
	}
}


int main() {
	fast;
	int t;
	cin >> t;
	while (t--)solve();
	return 0;
}