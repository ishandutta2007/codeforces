#include <bits/stdc++.h>
 
using namespace std;
 
#define MAXN 100100
 
typedef long long ll;
 
set<int> g[MAXN];
set<int> remaining;
int n, m;
 
void dfs(int p) {
	vector<int> candies;
	for (auto it = remaining.begin(); it != remaining.end(); it++) {
		if (g[p].find(*it) == g[p].end()) {
			candies.push_back(*it);
		}
	}
	for (int cand : candies) {
		remaining.erase(cand);
	}
	for (int cand : candies) {
		dfs(cand);
	}
}
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int from, to;
		cin >> from >> to;
		g[from].insert(to);
		g[to].insert(from);
	}
	for (int i = 1; i <= n; i++) {
		remaining.insert(i);
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (remaining.find(i) != remaining.end()) {
			ans++;
			remaining.erase(i);
			dfs(i);
		}
	}
	cout << ans - 1 << endl;
}