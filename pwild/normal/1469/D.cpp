#include <bits/stdc++.h>
using namespace std;

// 1 2 1 1 1 1 1 1 1 4

void solve(int n, bool print = true) {
	vector<pair<int,int>> res;
	
	int x = n;
	for (int i = n-1; i > 2; i--) {
		if (int64_t(i)*i < x) {
			res.emplace_back(n,i);
			x = (x+i-1)/i;
		}
		res.emplace_back(i,n);
	}
	while (x > 1) {
		res.emplace_back(n,2);
		x = (x+1)/2;
	}

	assert(int(res.size()) <= n+5);
	if (print) {
		cout << res.size() << '\n';
		for (auto [x,y]: res) cout << x << " " << y << '\n';
	}
}

int main() {
	int tc; cin >> tc;
	while (tc--) {
		int n; cin >> n;
		solve(n);
	}
}