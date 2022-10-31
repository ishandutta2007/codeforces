#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

int main()
{
#ifdef _MSC_VER
	freopen("e.in", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	int num_cases;
	cin >> num_cases;
	while (num_cases--) {
		int n, m;
		cin >> n >> m;
		vector<vector<int>> g(n);
		vector<vector<int>> reverse_g(n);
		for (int i = 0; i < m; i++) {
			int x, y;
			cin >> x >> y;
			--x;
			--y;
			g[x].push_back(y);
			reverse_g[y].push_back(x);
		}
		vector<int> in_degree(n);
		vector<int> tp_order;
		for (int i = 0; i < n; i++) {
			in_degree[i] = reverse_g[i].size();
			if (!in_degree[i]) {
				tp_order.push_back(i);
			}
		}
		vector<int> ret;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			int p = tp_order[i];
			a[p] = 1;
			for (int j : reverse_g[p]) {
				a[p] = max(a[p], a[j] + 1);
			}
			if (a[p] == 3) {
				ret.push_back(p);
				a[p] = 0;
			}
			for (int j : g[p]) {
				--in_degree[j];
				if (!in_degree[j]) {
					tp_order.push_back(j);
				}
			}
		}
		printf("%d\n", ret.size());
		for (int p : ret) {
			printf("%d ", p + 1);
		}
		printf("\n");
	}
	return 0;
}