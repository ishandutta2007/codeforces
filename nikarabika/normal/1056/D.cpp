//sobskdrbhvk
//remember... ):(
#include <bits/stdc++.h>

using namespace std;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())

typedef pair<int, int> pii;

const int maxn = 100 * 1000 + 10;
vector<int> adj[maxn];
int leaf[maxn],
	ans[maxn],
	n;
set<pii> s;

void dfs(int u = 0, int p = -1) {
	leaf[u] = !sz(adj[u]);
	for (auto v : adj[u]) {
		dfs(v);
		leaf[u] += leaf[v];
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i < n; i++) {
		int p;
		cin >> p, p--;
		adj[p].PB(i);
	}
	dfs();
	s.insert(MP(-leaf[0], 0));
	for (int i = n - 1; i >= 0; i--) {
		ans[i] = -s.begin()->L;
		int u = s.begin()->R;
		s.erase(s.begin());
		for (auto v : adj[u])
			s.insert(MP(-leaf[v], v));
	}
	for (int i = 0; i < n; i++)
		cout << ans[i] << ' ';
	cout << endl;
	return 0;
}