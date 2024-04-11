#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while(t--) {
		vector<pair<int, int>> moves;
		function<void(int)> Solve = [&](int n) {
			if (n == 2) return;
			int nxt = 2;
			while(nxt * nxt < n) ++nxt;
			for (int i = nxt + 1; i < n; ++i) moves.emplace_back(i, n);
			moves.emplace_back(n, nxt);
			moves.emplace_back(n, nxt);
			Solve(nxt);
		};
		int n; cin >> n;
		Solve(n);
		cout << moves.size() << "\n";
		for (pair<int, int> p : moves) cout << p.first << " " << p.second << "\n";
	}
	return 0;
}