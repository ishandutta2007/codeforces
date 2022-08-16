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

		string color;
		cin >> color;

		bool impossible = false;
		for (int i = 0; i < n; i++) {
			if (color[i] == 'B') {
				impossible |= a[i] < 1;
				a[i] = min(a[i], n);
			} else if (color[i] == 'R') {
				impossible |= a[i] > n;
				a[i] = max(a[i], 1);
			}
		}

		if (impossible) {
			cout << "NO\n";
			continue;
		}

		vector<int> blue, red;
		for (int i = 0; i < n; i++) {
			if (color[i] == 'B') {
				blue.push_back(a[i]);
			} else {
				red.push_back(a[i]);
			}
		}

		sort(blue.begin(), blue.end());

		bool possible = true;
		for (int i = 0; i < (int) blue.size(); i++) {
			possible &= blue[i] >= i + 1;
		}

		sort(red.begin(), red.end());
		for (int i = 0; i < (int) red.size(); i++) {
			possible &= red[i] <= blue.size() + i + 1;
		}

		cout << (possible ? "YES" : "NO") << '\n';
	}
	return 0;
}