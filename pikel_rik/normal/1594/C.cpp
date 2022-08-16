#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	constexpr int N = 300 * 1000;

	vector<vector<int>> divisors(N + 1);
	for (int i = 1; i <= N; i++) {
		for (int j = i; j <= N; j += i) {
			divisors[j].push_back(i);
		}
	}

	int t;
	cin >> t;

	while (t--) {
		int n; char c;
		cin >> n >> c;

		string s;
		cin >> s;

		int cnt = count(s.begin(), s.end(), c);
		if (cnt == n) {
			cout << 0 << '\n';
			continue;
		}

		vector<bool> marked(n + 1); marked[0] = true;
		for (int i = 0; i < n; i++) {
			if (s[i] != c) {
				for (int j: divisors[i + 1]) {
					marked[j] = true;
				}
			}
		}

		int idx = find(marked.begin(), marked.end(), false) - marked.begin();
		if (idx != n + 1) {
			cout << 1 << '\n';
			cout << idx << '\n';
		} else {
			cout << 2 << '\n';
			cout << n - 1 << ' ' << n << '\n';
		}
	}
	return 0;
}