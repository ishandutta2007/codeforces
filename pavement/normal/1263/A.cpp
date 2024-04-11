#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t, a[3];
	cin >> t;
	while (t--) {
		cin >> a[0] >> a[1] >> a[2];
		sort(a, a + 3);
		if (a[2] - a[0] <= a[1]) cout << (a[1] + a[2] - a[0]) / 2 + a[0];
		else cout << a[1] + a[0];
		cout << '\n';
	}
}