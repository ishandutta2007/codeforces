#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

void one_case() {
	int n;
	cin >> n;
	vector<vector<int>> vals(n);
	for (int i = 0; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		vals[i] = {a, b};
	}
	vector<vector<int>> graph(n);
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		--u;
		--v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	vector<int> que;
	vector<int> in_que(n);
	que.push_back(0);
	in_que[0] = 1;
	for (int close = 0; close < que.size(); ++close) {
		for (int next : graph[que[close]]) {
			if (!in_que[next]) {
				que.push_back(next);
				in_que[next] = 1;
			}
		}
	}
	vector<vector<long long>> dp(n);
	for (int close = que.size() - 1; close >= 0; --close) {
		int cur = que[close];
		dp[cur] = vector<long long>(2);
		for (int next : graph[que[close]]) {
			if (!dp[next].empty()) {
				for (int i = 0; i < 2; ++i) {
					dp[cur][i] += max(dp[next][0] + abs(vals[next][0] - vals[cur][i]), 
									  dp[next][1] + abs(vals[next][1] - vals[cur][i]));
				}
			}
		}
	}
	cout << max(dp[0][0], dp[0][1]) << endl;
}

int main()
{
#ifdef _MSC_VER
	freopen("a.in", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		one_case();
	}
	return 0;
}