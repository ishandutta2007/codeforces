/*
	Two nodes are the same ---> Two subtrees are eliminated
	Three nodes with same value on one path --> answer = 0
	Suppose no three nodes in one path (1) --> keep eliminating subtree?
	Where to root tree initially?

	Suppose (1) holds --> the same value nodes define a "subgraph"
	Union of all these subgraphs is the answer

	How to check (1)?
	Any value a[i] appearing multiple times will delete subtree down to leaves
	Delete edges which do not lead to another a[i] --> there is at most one edge that leads to another a[i]
	If there are more than one --> (1) satisfies, answer = 0
*/

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

int n; map<int, int> mp;
vector<int> adj[MAXN];
vector<int> a(MAXN);

int tmm = 0;
vector<int> euls(1);
int tin[MAXN], tout[MAXN]; 

void dfs(int now, int prev) {
	euls.push_back(now);
	tin[now] = ++tmm;

	for (int u: adj[now]) {
		if (u != prev) dfs(u, now);
	}

	tout[now] = tmm;
}

map<int, int> s;
vector<int> pref(MAXN);

void dfs2(int now, int prev) {
	map<int, int> t;
	t[a[now]]++;

	// find that pointer edge, count how many pointer edges we have
	int peck = 0, nd = -1;
	for (int u: adj[now]) {
		if (u != prev) {
			dfs2(u, now);
			if (s.find(a[now]) != s.end()) {
				peck++; nd = u;
			}

			if (s.size() > t.size()) s.swap(t);
			for (auto [col, val]: s) t[col] += val;
		}
	}

	// if not enough, pecking edge must be on top
	if (t[a[now]] != mp[a[now]]) {
		peck++; nd = -1;
	}
	s.swap(t);

	if (peck > 1) {cout << "0\n"; exit(0);}
	if (peck == 0) return;

	if (nd == -1) {
		pref[1]++; pref[tin[now]]--;
		pref[tout[now] + 1]++; pref[n+1]--;
	} else {
		pref[tin[nd]]++; pref[tout[nd] + 1]--;
	}
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		mp[a[i]]++;
	}
	int non_unique = 0;
	for (auto [col, val]: mp) {
		if (val > 1) non_unique += val;
	}

	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1, 0);
	dfs2(1, 0);

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		pref[i] += pref[i-1];
		if (pref[i] == non_unique) ans++;
	}
	cout << ans << '\n';

	return 0;
}