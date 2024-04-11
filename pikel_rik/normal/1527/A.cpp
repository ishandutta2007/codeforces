#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		int msb = 32 - __builtin_clz(n) - 1;
		cout << (1 << msb) - 1 << '\n';
	}
	return 0;
}