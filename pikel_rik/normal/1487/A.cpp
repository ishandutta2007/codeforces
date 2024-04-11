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

		int mn = *min_element(a.begin(), a.end());
		cout << n - count(a.begin(), a.end(), mn) << '\n';
	}
	return 0;
}