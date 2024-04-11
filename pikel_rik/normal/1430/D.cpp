#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		string s;
		cin >> s;

		vector<int> lens;

		int cur = 1;
		for (int i = 1; i < n; i++) {
			if (s[i] != s[i - 1]) {
				lens.push_back(cur);
				cur = 1;
			} else {
				cur++;
			}
		}
		lens.push_back(cur);

		int moves = 0;
		for (int i = 0; i < lens.size(); i++) {
			moves += lens[i] - 1;
			moves = min(moves, i + 1);
		}

		if (moves >= lens.size()) {
			cout << lens.size() << '\n';
		} else {
			cout << moves + (lens.size() - moves + 1) / 2 << '\n';
		}
	}
	return 0;
}