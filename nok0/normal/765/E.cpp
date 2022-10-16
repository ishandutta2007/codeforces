#include <bits/stdc++.h>
using namespace std;

int n, i, u, v, root;
int main() {
	cin >> n;
	vector g(n, vector(0, 0));
	for(i = 0; i < n - 1; i++) {
		cin >> u >> v;
		g[--u].push_back(--v);
		g[v].push_back(u);
	}
	auto dfs = [&](auto dfs, int now, int per) -> int {
		set<int> lens;
		for(auto to : g[now]) {
			if(to != per) {
				int val = dfs(dfs, to, now) + 1;
				if(val)
					lens.insert(val);
				else
					return -1;
			}
		}
		if(lens.size() > 2) return -1;
		if(lens.size() == 1) return *lens.begin();
		if(lens.empty()) return 0;
		if(now == root) return *lens.begin() + *lens.rbegin();
		root = now;
		return -1;
	};
	dfs(dfs, root, -1);
	auto res = dfs(dfs, root, -1);
	while(res % 2 == 0) res /= 2;
	cout << res << '\n';
}