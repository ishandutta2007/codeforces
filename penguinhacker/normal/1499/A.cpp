#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while(t--) {
		int n, a, b, w, k; cin >> n >> a >> b >> w >> k;
		int x = (a + b) / 2;
		int y = (2 * n - a - b) / 2;
		cout << (x >= w && y >= k ? "YES" : "NO") << "\n";
	}
	return 0;
}