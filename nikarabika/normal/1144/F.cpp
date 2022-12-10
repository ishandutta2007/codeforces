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

const int maxn = 2e5 + 10;
int mark[maxn],
	col[maxn],
	frm[maxn],
	too[maxn],
	n, m;
vector<int> adj[maxn];

void dfs(int u) {
	mark[u] = true;
	for (auto e : adj[u]) {
		int v = frm[e] ^ too[e] ^ u;
		if (!mark[v]) {
			col[v] = !col[u];
			dfs(v);
		}
		else if (col[u] == col[v]) {
			cout << "NO\n";
			exit(0);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> frm[i] >> too[i];
		frm[i]--, too[i]--;
		adj[frm[i]].PB(i);
		adj[too[i]].PB(i);
	}
	dfs(0);
	cout << "YES\n";
	for (int i = 0; i < m; i++)
		cout << col[frm[i]];
	cout << '\n';
	return 0;
}