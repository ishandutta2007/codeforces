#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n, m;
		cin >> n >> m;

		long long x;
		cin >> x, --x;

		int r = x % n, c = x / n;
		cout << (long long)r * m + c + 1 << '\n';
	}
	return 0;
}