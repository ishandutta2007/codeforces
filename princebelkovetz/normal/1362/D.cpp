#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <unordered_set>
#include <queue>
#define int long long
#define endl "\n";
using namespace std;

void solve(){
	int n, m, u, v;
	cin >> n >> m;
	vector <int> ans;
	vector <vector<int>> a(n + 1);
	vector <int> used(n + 1, 1);
	vector <pair <int, int>> temp;
	for (int i = 0; i < m; ++i) {
		cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	for (int i = 1; i <= n; ++i) {
		cin >> u;
		temp.push_back({ u, i });
	}
	sort(temp.begin(), temp.end());
	for (int i = 0; i < n; ++i) {
		v = used[temp[i].second];
		for (auto u : a[temp[i].second]) {
			if (used[u] == v) used[u]++;
		}
		if (v != temp[i].first) {
			cout << -1; return;
		}
	}
	for (int i = 0; i < n; ++i) {
		cout << temp[i].second << " ";
	}


}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(15);
	int t;
	t = 1;
	while (t--) {
		solve();
	}
	return 0;
}