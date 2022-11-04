#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define sz(x) (int) x.size()
#define INF (int) 1e9
#define LINF (ll) 1e18
#define EPS 1e-10
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define eq(a, b) abs(a - b) < EPS

int n, m;
vector<vector<int>> g;
vector<vector<int>> ng;
vector<int> cnt;
vector<int> pre_ans;
vector<int> most_far;
vector<int> ans;
vector<bool> attacked;

void dfs(int v, int from) {
	for (int to : g[v]) {
		if (to != from) {
			dfs(to, v);
			ng[v].push_back(to);
			cnt[v] += cnt[to];
			if (cnt[to]) {
				pre_ans[v] += pre_ans[to] + 2;
				most_far[v] = max(most_far[v], most_far[to] + 1);
			}
		}
	}

	if (attacked[v]) {
		cnt[v]++;
		most_far[v] = max(most_far[v], 0);
	}
}

void solve(int v, int top_ans, int top_cnt, int top_dist) {
	if (v == 0) {
		ans[0] = pre_ans[v] - most_far[0];
	} else {
		ans[v] = pre_ans[v];
		int minus = most_far[v];
		if (top_cnt) {
			ans[v] += top_ans + 2;
			minus = max(minus, top_dist + 1);
		}
		ans[v] -= minus;
	}

	int k = sz(g[v]);
	vector<int> prefix_max(k);
	vector<int> suffix_max(k);

	if (k) {
		prefix_max[0] = most_far[g[v][0]];
		suffix_max[k - 1] = most_far[g[v][k - 1]];

		for (int i = 1; i < k; i++) {
			prefix_max[i] = max(prefix_max[i - 1], most_far[g[v][i]]);
			suffix_max[k - i - 1] = max(suffix_max[k - i], most_far[g[v][k - i - 1]]);
		}
	}

	for (int i = 0; i < k; i++) {
		int to = g[v][i];

		if (cnt[to]) {
			int nans = pre_ans[v] - pre_ans[to] - 2;
			if (top_cnt) {
				nans += top_ans + 2;
			}
			int ndist = 0;
			if (top_cnt != 0) {
				ndist = top_dist + 1;
			}
			if (i > 0) {
				ndist = max(ndist, prefix_max[i - 1] + 1);
			}
			if (i < k - 1) {
				ndist = max(ndist, suffix_max[i + 1] + 1);
			}

			solve(to, nans, top_cnt + cnt[v] - cnt[to], ndist);
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);

	cin >> n >> m;

	g.resize(n);
	ng.resize(n);
	cnt.resize(n);
	pre_ans.resize(n);
	most_far.resize(n, -INF);
	attacked.resize(n);
	ans.resize(n, INF);

	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		g[u].pb(v);
		g[v].pb(u);
	}

	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		x--;
		attacked[x] = true;
	}

	dfs(0, -1);
	g = ng;
	solve(0, 0, 0, 0);

	int t = *min_element(ans.begin(), ans.end());
	for (int i = 0; i < n; i++) {
		if (ans[i] == t) {
			cout << i + 1 << "\n" << t << "\n";
			return 0;
		}
	}

	/*for (int i = 0; i < n; i++) {
		cout << i + 1 << " " << ans[i] << endl;
	}*/

    return 0;
}