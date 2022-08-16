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

		string s;
		cin >> s;

		string ss = s;
		sort(ss.begin(), ss.end());
		int distinct = unique(ss.begin(), ss.end()) - ss.begin();

		cout << (distinct == unique(s.begin(), s.end()) - s.begin() ? "YES" : "NO") << '\n';
	}
	return 0;
}