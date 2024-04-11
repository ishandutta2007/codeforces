#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	
	int n, m, x, y;
	cin >> n >> m;
	int ans = 1e9;
	while (m--) {
		cin >> x >> y;
		ans = min(ans, y-x);
	}
	cout << ++ans << '\n';
	for (int i = 0; i < n; i++) {
		cout << i % ans << ' ';
	}
	
	return 0;
}