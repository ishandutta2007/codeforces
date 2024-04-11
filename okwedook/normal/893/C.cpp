#include <bits/stdc++.h>

using namespace std;
vector<int> G[100001];
vector<long long> c(100001);
vector<bool> used(100001);

long long dfs(int v) {
	long long ans = c[v];
	used[v] = true;
	for (int i : G[v])
		if (!used[i])
			ans = min(ans, dfs(i));
	return ans;
}
 
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i) cin >> c[i];
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	long long ans = 0;
	for (int i = 0; i < n; ++i)
		if (!used[i])
			ans += dfs(i);
	cout << ans;
	//system("pause");
    return 0;
}