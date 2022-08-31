#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n, a, b;
		cin >> n >> a >> b, --a, --b;

		vector<int> p(n);
		p[0] = a, p[n - 1] = b;
		for (int i = 1, j = n - 1; i < n - 1; i++) {
			while (j == a || j == b) {
				j -= 1;
			}
			p[i] = j;
			j -= 1;
		}

		if (*min_element(p.begin(), p.begin() + n / 2) == a && *max_element(p.begin() + n / 2, p.end()) == b) {
			for (auto &x : p) {
				cout << x + 1 << ' ';
			}
			cout << '\n';
		} else {
			cout << "-1\n";
		}
	}
	return 0;
}