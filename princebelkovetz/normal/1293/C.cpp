#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#define endl "\n";
//define int long long
using namespace std;

void solve() {
	int n, q, u, v, cnt = 0;
	cin >> n >> q;
	vector <vector <int>> save(3, vector <int>(n + 2, 0)) ;
	for (int i = 0; i < q; ++i) {
		cin >> u >> v;
		save[u][v] = 1 - save[u][v];
		if (save[u][v]) {
			if (save[3 - u][v - 1])cnt++;
			if (save[3 - u][v])cnt++;
			if (save[3 - u][v + 1])cnt++;
		}
		else {
			if (save[3 - u][v - 1])cnt--;
			if (save[3 - u][v])cnt--;
			if (save[3 - u][v + 1])cnt--;
		}
		if (cnt) cout << "nO\n";
		else cout << "yEs\n";
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