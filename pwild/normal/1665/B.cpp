#include <bits/stdc++.h>
using namespace std;

int solve() {
	int n; cin >> n;
	
	map<int,int> count;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		count[x]++;
	}
	
	int cmax = 0;
	for (auto [_,c]: count) {
		cmax = max(cmax,c);
	}

	int res = n-cmax;
	while (cmax < n) cmax *= 2, res++;
	return res;
}

int main() {
	int tc; cin >> tc;
	while (tc--) {
		cout << solve() << '\n';
	}
}