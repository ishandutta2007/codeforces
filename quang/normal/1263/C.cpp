#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int tc; cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		vector<int> res;
		for (int i = 1; i <= n; i = n / (n / i) + 1) {
			res.push_back(n / i);
		}
		res.push_back(0);
		reverse(res.begin(), res.end());
		cout << res.size() << '\n';
		for (int u : res) cout << u << ' ';
		cout << '\n';
	}
	return 0;
}