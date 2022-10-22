#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN = 200000;
int n;
ll a[mxN];
bool take[mxN];
vector<int> adj[mxN];
vector<int> roots;
ll ans = 0;

void dfs1(int u) {
	for (int v : adj[u]) {
		dfs1(v);
		if (a[v] > 0) {
			take[v] = 1;
			a[u] += a[v];
		}
	}
	ans += a[u];
}

vector<int> ord;
void dfs2(int u) {
	for (int v : adj[u]) {
		if (take[v]) {
			dfs2(v);
		}
	}
	ord.push_back(u);
	for (int v : adj[u]) {
		if (!take[v]) {
			dfs2(v);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		if (x != -1) {
			adj[x - 1].push_back(i);
		}
		else {
			roots.push_back(i);
		}
	}
	for (int i : roots) {
		dfs1(i);
		dfs2(i);
	}
	cout << ans << "\n";
	assert(ord.size() == n);
	for (int i = 0; i < n; ++i) {
		if (i > 0) {
			cout << " ";
		}
		cout << ord[i] + 1;
	}
	return 0;
}