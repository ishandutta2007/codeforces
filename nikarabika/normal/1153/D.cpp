//sobskdrbhvk
//remember...
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

const int maxn = 3e5 + 10;
int op[maxn],
	ans[maxn],
	cnt[maxn],
	n;
vector<int> adj[maxn];

void dfs(int u) {
	if (sz(adj[u]) == 0)
		ans[u] = cnt[u] = 1;
	else if (op[u])
		ans[u] = 1e8;
	else
		ans[u] = 0;
	for (auto v : adj[u]) {
		dfs(v);
		cnt[u] += cnt[v];
		if (op[u])
			smin(ans[u], ans[v]);
		else
			ans[u] += ans[v];
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> op[i];
	for (int i = 1; i < n; i++) {
		int x;
		cin >> x, x--;
		adj[x].PB(i);
	}
	dfs(0);
	cout << cnt[0] - ans[0] + 1 << endl;
	return 0;
}