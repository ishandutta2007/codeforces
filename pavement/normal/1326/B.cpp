#include <bits/stdc++.h>
using namespace std;
#define int long long

int b[200005];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> b[i];
	for (int i = 1, curm = 0; i <= n; i++) {
		if (b[i] <= 0) {
			cout << curm + b[i] << ' ';
		} else {
			curm += b[i];
			cout << curm << ' ';
		}
	}
	cout << '\n';
}