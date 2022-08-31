#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int a, b;
		cin >> a >> b;

		int alice = (a + b + 1) / 2;
		int bob = a + b - alice;

		set<int> breaks;
		for (int i = 0; i <= min(a, alice); i++) {
			if (bob >= a - i) {
				breaks.insert(a - i + alice - i);
			}
		}

		swap(alice, bob);
		for (int i = 0; i <= min(a, alice); i++) {
			if (bob >= a - i) {
				breaks.insert(a - i + alice - i);
			}
		}

		cout << breaks.size() << '\n';
		for (auto &x : breaks) {
			cout << x << ' ';
		}
		cout << '\n';
	}
	return 0;
}