#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <iomanip>

using namespace std;
#define int long long
#define ld long double
#define debug(x) cout << #x << " is " << x << '\n';
const int mod = 1e9 + 7;

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(6);
	int tt; cin >> tt;
	while (tt --> 0) {
		int n; cin >> n;
		vector <int> a(n);
		for (auto& x : a) cin >> x;
		vector <int> ans1, ans2;
		set <int> a1, a2;
		for (int i = 1; i <= n; ++i)
			a1.insert(i), a2.insert(i);
		int last = 0;
		for (int i = 0; i < n; ++i) {
			ans1.push_back(a[i]);
			ans2.push_back(a[i]);
			a1.erase(a[i]);
			a2.erase(a[i]);
			int j = i;
			while (j < n and a[j] == a[i]) j++;
			auto it = a1.begin();
			for (int k = 0; k < j - i - 1; ++k) {
				ans1.push_back(*it);
				it++;
			}
			for (int k = 0; k < j - i - 1; ++k)
				a1.erase(ans1[ans1.size() - 1 - k]);
			it = a2.lower_bound(a[i]);
			for (int k = 0; k < j - i - 1; ++k) {
				it--;
				ans2.push_back(*it);
			}
			for (int k = 0; k < j - i - 1; ++k)
				a2.erase(ans2[ans2.size() - 1 - k]);
			i = j - 1;
		}
		for (auto x : ans1) cout << x << ' ';
		cout << '\n';
		for (auto x : ans2) cout << x << ' ';
		cout << '\n';

	}
	return 0;
}