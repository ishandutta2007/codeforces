#include <bits/stdc++.h>

using namespace std;


void solve() {
	int n;
	cin >> n;
	if (n == 3) {
		cout << "-1\n";
		return;
	}
	if (n % 2 == 0) {
		for (int i = 1; i <= n; ++i) {
			cout << ((i - 1) ^ 1) + 1 << " \n"[i == n];
		}
		return;
	}
	else {
		cout << n << " " << n - 1 << " ";
		for (int i = 1; i <= n - 2; ++i) {
			cout << i << " \n"[i == n - 2];
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}