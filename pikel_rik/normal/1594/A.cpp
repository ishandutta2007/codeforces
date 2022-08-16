#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		long long n;
		cin >> n;

		cout << -(n - 1) << ' ' << n << '\n';
	}
	return 0;
}