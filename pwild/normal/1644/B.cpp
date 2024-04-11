#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
	int n; cin >> n;

	vector<vector<int>> res;
	if (n == 3) {
		res = {{3,2,1},{1,3,2},{3,1,2}};
	} else {
		vector<int> p(n);
		iota(begin(p), end(p), 1);
		p[0] = 3, p[1] = 1, p[2] = 2;
		for (int i = 0; i < n; i++) {
			rotate(begin(p), begin(p)+1, end(p));
			res.push_back(p);
		}
	}

	for (auto p: res) {
		for (int j = 0; j < n; j++) {
			cout << p[j] << " \n"[j+1==n];
		}
	}
}

int main() {
	int tc; cin >> tc;
	while (tc--) solve();
}