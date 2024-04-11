#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 3e18;
const int OO = 0;
using namespace std;

ll pw(ll b, ll e) {
	b %= md;
	ll res = 1;
	while (e) {
		if (e & 1) res = res * b % md;
		e /= 2, b = b * b % md;
	}
	return res;
}
ll inv(ll x) {
	return pw(x, md - 2);
}

const int N = 205;
const ll inv2 = ll(md + 1) / 2;

int n;
ll dp[N][N];
vector<vector<int>> g;
int col[N];
ll invn;
ll result;

void prep() {
	for (int i = 1; i < N; i++)
		dp[i][0] = 1, dp[0][i] = 0;
	for (int i = 1; i < N; i++) {
		for (int j = 1; j < N; j++) {
			dp[i][j] = inv2 * (dp[i - 1][j] + dp[i][j - 1]) % md;
		}
	}
}

void bfs(const vector<int> &a) {
	for (int i = 0; i < n; i++) col[i] = -1;
	queue<int> q;
	for (int i = 0; i < a.size(); i++) {
		q.push(a[i]);
		col[a[i]] = i;
	}
	while (q.size()) {
		int x = q.front();
		q.pop();
		for (const auto &i : g[x]) {
			if (col[i] == -1) {
				col[i] = col[x];
				q.push(i);
			}
		}
	}
	if (OO) {
		cout << "bfs on: ";
		for (const auto &i : a) cout << i << " "; cout << '\n';
		cout << "result: ";
		for (const auto &i : col) cout << i << " "; cout << '\n';
	}
}
ll findprob(int d) {
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		int b = col[i];
		ans = (ans + dp[b][d - b]) % md;
	}
	if (OO) {
		cout << "findprob " << ans << " " << invn << '\n';
		cout << "findprob: " << invn * ans % md << '\n';
	}
	return invn * ans % md;
}

void dfs(int root, int v, int prev, vector<int> &path) {
	path.push_back(v);
	if (root < v) {
		bfs(path);
		result = (result + findprob((int)path.size() - 1)) % md;
	}
	for (const auto &i : g[v]) {
		if (i != prev) {
			dfs(root, i, v, path);
		}
	}
	path.pop_back();
}

void solve() {
	cin >> n;
	invn = inv(n);
	g.resize(n);
	for (int i = 0, u, v; i < n - 1; i++) {
		cin >> u >> v;
		--u, --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	result = 0;
	vector<int> path;
	for (int i = 0; i < n; i++) {
		dfs(i, i, -1, path);
	}
	cout << result << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	prep();
	int tst = 1;
	//cin >> tst;
	while (tst--) solve();
}