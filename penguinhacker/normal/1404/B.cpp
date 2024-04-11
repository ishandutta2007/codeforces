#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e5;
int n, a, b, da, db;
vector<int> adj[mxN];

ar<int, 2> dfs(int u=0, int p=-1) { //return {diameter, to child}
	ar<int, 2> best={0, 0};
	int diam=0;
	for (int v : adj[u]) if (v!=p) {
		ar<int, 2> cur=dfs(v, u);
		if (cur[1]+1>best[0]) {
			best[1]=best[0];
			best[0]=cur[1]+1;
		}
		else if (cur[1]+1>best[1]) {
			best[1]=cur[1]+1;
		}
		diam=max(diam, cur[0]);
	}
	diam=max(diam, best[0]+best[1]);
	return {diam, best[0]};
}

int dist(int u=a, int p=-1) {
	if (u==b) return 0;
	for (int v : adj[u]) if (v!=p) {
		int x=dist(v, u);
		if (x!=-1) return x+1;
	}
	return -1;
}

void solve() {
	cin >> n >> a >> b >> da >> db, --a, --b;
	for (int i=0; i<n; ++i) {
		adj[i].clear();
	}
	for (int i=1; i<n; ++i) {
		int x, y; cin >> x >> y, --x, --y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	int diam=dfs()[0];
	//cout << "DIAM" << " " << diam << "\n";
	int x=min(db, diam);
	//cout << dist() << "\n";
	if (dist()<=da) {cout << "Alice\n"; return;}
	if (x>=2*da+1) cout << "Bob\n";
	else cout << "Alice\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}