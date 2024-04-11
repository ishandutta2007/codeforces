#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 2e18;
const int OO = 1;
const int OOO = 1;
using namespace std;

struct opt {
	pair<int, int> A, B;
	opt() {
		A = { 0, 0 };
		B = { 1, 0 };
	}
	void add(int key, int value) {
		if (value > B.second) {
			B = { key, value };
			if (A.second < B.second) swap(A, B);
		}
	}
	int query(int without) {
		if (A.first == without) return B.second;
		return A.second;
	}
};

int n;
vector<vector<int>> g;
vector<int> dp[2];
vector<vector<int>> need;
vector<opt> a[2];
/*
void calc(int v, int pre) {
	dp[1][v] = dp[0][v] = 0;
	int add = (pre == -1 ? (int)g[v].size() : (int)g[v].size() - 1);
	add = max(0, add - 1);
	for (const auto &i : g[v]) {
		if (i != pre) {
			calc(i, v);
			dp[1][v] = max(dp[1][v], dp[0][i]);
			dp[0][v] = max(dp[0][v], max(dp[0][i], dp[1][i]));
		}
	}
	dp[1][v]++;
	dp[0][v] += add;
	//cout << v << " " << dp[1][v] << " " << dp[0][v] << endl;
}
*/

void calc(int v, int pre) {
	for (int i = 0; i < need[v].size(); i++)
		if (need[v][i] == pre) {
			swap(need[v][0], need[v][i]);
			break;
		}
	a[1][v].add(-1, 1);
	a[0][v].add(-1, 0);
	while (need[v].size() && need[v].back() != pre) {
		int u = need[v].back();
		need[v].pop_back();
		calc(u, v);
		int val = a[0][u].query(v);
		a[1][v].add(u, val + 1);
		val = max(val, a[1][u].query(v));
		a[0][v].add(u, val + (g[v].size() - 2));
	}
}

int calc2(int v) {
	//cout << "v " << v + 1 << endl;
	int mx1 = 0, mx2 = 0;
	for (const auto &i : g[v]) {
		mx1 = max(mx1, a[0][i].query(v));
		mx2 = max(mx2, max(a[0][i].query(v), a[1][i].query(v)));
	}
	//cout << mx1 << " " << mx2 << endl;
	mx1++;
	mx2 += g[v].size() - 1;
	return max(mx1, mx2);
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	g.resize(n);
	dp[0].resize(n);
	dp[1].resize(n);
	need.resize(n);
	for (int i = 0, u, v; i < n - 1; i++) {
		cin >> u >> v;
		--u, --v;
		g[u].push_back(v);
		g[v].push_back(u);
		need[u].push_back(v);
		need[v].push_back(u);
	}
	a[0].resize(n);
	a[1].resize(n);
	/*
	calc(0, -1);
	cout << max(dp[0][0], dp[1][0]) << endl;
	*/
	for (int i = 0; i < n; i++) {
		for (const auto &j : g[i])
			calc(i, j);
	}
	/*
	while (1) {
		int v, u;
		cin >> v >> u;
		--v, --u;
		cout << a[0][v].query(u) << " " << a[1][v].query(u) << endl;
	}
	*/
	

	int ans = 0;
	for (int i = 0; i < n; i++)
		ans = max(ans, calc2(i));
	cout << ans << endl;
}