#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define arr array

int n, m, a, b, cnt1, cnt2;
bool visited1[200000], visited2[200000];
vector<int> adj[200000];

void init() {
	cnt1=-1; //exclude city a
	cnt2=-1; //exclude city b
	cin >> n >> m >> a >> b, a--, b--;
	for (int i=0; i<n; ++i) {
		adj[i].clear();
		visited1[i]=0;
		visited2[i]=0;
	}
	for (int i=0; i<m; ++i) {
		int x, y;
		cin >> x >> y, x--, y--;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
}

void dfs1(int s) {
	if (visited1[s] || s==b)
		return;
	visited1[s]=1;
	cnt1++;
	for (int i : adj[s])
		dfs1(i);
}

void dfs2(int s) {
	if (visited2[s] || s==a)
		return;
	visited2[s]=1;
	if (visited1[s])
		cnt1--;
	else
		cnt2++;
	for (int i : adj[s])
		dfs2(i);
}

void solve() {
	init();
	dfs1(a);
	dfs2(b);
	cout << 1ll*cnt1*cnt2 << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--)
		solve();

	return 0;
}