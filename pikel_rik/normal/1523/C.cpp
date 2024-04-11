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

		vector<int> st;
		for (int i = 0; i < n; i++) {
			if (a[i] == 1) {
				st.push_back(1);
			} else {
				while (!st.empty() && st.back() + 1 != a[i]) {
					st.pop_back();
				}
				st.back() += 1;
			}
			string s = to_string(st[0]);
			for (int j = 1; j < st.size(); j++) {
				s += '.';
				s += to_string(st[j]);
			}
			cout << s << '\n';
		}
	}
	return 0;
}