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

		vector<int> a(n);
		for (auto &x : a) cin >> x;

		sort(a.rbegin(), a.rend());

		int turn = 0;
		long long alice = 0, bob = 0;
		for (auto x : a) {
			if (turn % 2 == 0) {
				if (x % 2 == 0) {
					alice += x;
				}
			} else {
				if (x % 2 != 0) {
					bob += x;
				}
			}
			turn ^= 1;
		}

		if (alice > bob)
			cout << "Alice\n";
		else if (alice < bob)
			cout << "Bob\n";
		else cout << "Tie\n";
	}
	return 0;
}