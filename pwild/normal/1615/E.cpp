#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<vector<int>> adj;
vector<int> leaves;

long long score(int r, int b) {
	int w = n - r - b;
	return w * 1LL * (r-b);
}

int dfs(int i, int p) {
	vector<int> children;
	for (int j: adj[i]) if (j != p) {
		children.push_back(dfs(j,i)+1);
	}
	if (children.empty()) return 0;

	auto it = max_element(begin(children), end(children));
	int res = *it;
	children.erase(it);
	copy(begin(children), end(children), back_inserter(leaves));
	return res;
}

int main() {
	cin >> n >> k;
	
	adj.resize(n);
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	leaves.push_back(dfs(0,-1)+1);

	if (ssize(leaves) <= k) {
		int r = max(int(size(leaves)), min(k, n/2));
		cout << score(r, 0) << '\n';
		return 0;
	}
	
	sort(begin(leaves), end(leaves), greater<int>());
	leaves.resize(k);

	int sum = accumulate(begin(leaves), end(leaves), 0);
	cout << score(size(leaves), min(n/2, n-sum)) << '\n';
}