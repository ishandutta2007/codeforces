#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

int main()
{
#ifdef _MSC_VER
	freopen("d.in", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<long long> w(n);
	for (int i = 0; i < n; i++) {
		int c;
		cin >> c;
		w[i] = c;
	}
	vector<long long> h(n);
	for (int i = 0; i < n; i++) {
		int c;
		cin >> c;
		h[i] = c;
	}
	vector<int> deg(n);
	vector<vector<int>> g(n);
	long long result = 0;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		--u;
		--v;
		result += (w[u] + w[v]);
		if (h[u] == h[v]) {
			g[u].push_back(v);
			g[v].push_back(u);
		}
		else {
			if (h[u] > h[v]) {
				swap(u, v);
			}
			++deg[u];
			--deg[v];
		}
	}
	vector<int> vis(n);
	std::function<vector<long long>(int)> dfs = [&](int p) {
		vis[p] = 1;
		long long s0 = 0;
		vector<long long> delta;
		for (int x : g[p]) {
			if (!vis[x]) {
				vector<long long> t = dfs(x);
				s0 += t[0];
				delta.push_back(t[2] - t[0]);
			}
		}
		sort(delta.begin(), delta.end());
		int m = delta.size();
		vector<long long> ret;
		for (int target = -1; target <= 1; target++) {
			long long min_cost = (1LL << 60);
			long long s = s0;
			for (int c1 = 0; c1 <= m; c1++) {
				if (c1 > 0) {
					s += delta[c1 - 1];
				}
				long long d = deg[p] + c1 - (m - c1);
				min_cost = min(min_cost, s + abs(d - target) * w[p]);
			}
			ret.push_back(min_cost);
		}
		return ret;
	};
	for (int i = 0; i < n; i++) {
		if (!vis[i]) {
			vector<long long> r = dfs(i);
			result += r[1];
		}
	}
	cout << result / 2 << endl;
	return 0;
}