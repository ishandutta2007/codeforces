#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int k;
	cin >> k;

	while (k--) {
		int n, x, t;
		cin >> n >> x >> t;

		int people = min(n - 1, t / x);
		cout << (long long)(n - people) * people + (long long)people * (people - 1) / 2 << '\n';
	}
	return 0;
}