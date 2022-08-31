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

		vector<int> a(n), cnt(n);
		for (auto& item : a) {
			cin >> item;
			cnt[--item]++;
		}

		int ans = -1;
		for (int i = 0; i < n; i++) {
			if (cnt[i] == 1) {
				ans = i;
				break;
			}
		}

		if (ans == -1) {
			cout << "-1\n";
		} else {
			int idx = find(a.begin(), a.end(), ans) - a.begin() + 1;
			cout << idx << '\n';
		}
	}
	return 0;
}