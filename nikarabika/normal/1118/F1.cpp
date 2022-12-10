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

const int maxn = 1e6;
vector<int> adj[maxn];
int cnt[2],
	col[2][maxn];
int n, ans;
int a[maxn];

void dfs(int u, int p = -1) {
	if (~a[u])
		col[a[u]][u]++;
	for (auto v : adj[u])
		if (v ^ p) {
			dfs(v, u);
			col[0][u] += col[0][v];
			col[1][u] += col[1][v];
		}
	for (int i = 0; i < 2; i++)
		if (col[i][u] == cnt[i] and col[i^1][u] == 0) {
			ans++;
			return;
		}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i], a[i]--;
		if (~a[i])
			cnt[a[i]]++;
	}
	for (int i = 1; i < n; i++) {
		int fi, se;
		cin >> fi >> se;
		fi--, se--;
		adj[fi].PB(se);
		adj[se].PB(fi);
	}
	dfs(0);
	cout << ans << endl;
	return 0;
}