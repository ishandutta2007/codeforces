#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n; cin >> n;
	vector<int> p(n);
	for (int &x: p) cin >> x;
	string s; cin >> s;

	vector<tuple<int,int,int>> a;
	for (int i = 0; i < n; i++) {
		a.emplace_back(s[i], p[i], i);
	}
	sort(begin(a), end(a));
	
	int y = 1;
	for (auto [c,x,i]: a) {
		p[i] = y++;
	}
	
	for (int x: p) cout << x << " ";
	cout << '\n';
}

// 0 1 1 1 0 0 0 1
// 2 3 1 8 5 4 7 6
// 1 6 5 8 3 2 4 7


int main() {
	int tc; cin >> tc;
	while (tc--) solve();
}