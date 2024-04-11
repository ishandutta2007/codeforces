#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <queue>
using namespace std;
void print(vector <int> a) {
	for (auto x : a) {
		cout << x << " ";
	}
	cout << endl;
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(15);
	int n, m, u, v, ans = 0;
	cin >> n >> m;
	vector <int> b(n + 1), cur(n + 1, 0);
	for (int i = 1; i <= n; ++i) {
		cin >> b[i];
	}
	vector <vector <int>> a(n + 1);
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		if (u == v) continue;
		a[u].push_back(v);
		a[v].push_back(u);
		cur[u] += b[v];
		cur[v] += b[u];
	}
	//print(b); print(cur);
	while (true) {
		int min = 0, ind = 0;
		for (int i = 1; i <= n; ++i) {
			if (b[i] > max(min, 0)) {
				ind = i; min = b[i];
			}
		}
		if (!ind) break;
		ans += cur[ind];
		cur[ind] = 0; 
		for (auto u : a[ind]) {
			cur[u] -= b[ind];
		}
		b[ind] = 0;
		//print(cur);
	}
	cout << ans; 
	return 0;
	
}