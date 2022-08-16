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

		vector<int> a(n);
		for (auto& aa : a) cin >> aa;

		map<int, int> mp1, mp2;
		for (int i : a) {
			mp2[i]++;
		}

		vector<int> ans;

		for (int i = 0; i < n; i++) {
			mp1[a[i]]++;
			mp2[a[i]]--;
			if (!mp2[a[i]]) {
				mp2.erase(a[i]);
			}
			if (mp1.size() == i + 1 && mp1.rbegin()->first == i + 1 && mp2.size() == n - i - 1 && mp2.rbegin()->first == n - i - 1) {
				ans.push_back(i + 1);
			}
		}

		cout << ans.size() << '\n';
		for (int i : ans) {
			cout << i << ' ' << n - i << '\n';
		}
	}
	return 0;
}