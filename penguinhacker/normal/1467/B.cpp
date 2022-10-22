#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		vector<int> a(n); for (int& i : a) cin >> i;
		
		auto solve = [&](vector<int> v) {
			int res = 0;
			for (int i = 1; i + 1 < (int)v.size(); ++i) {
				res += (v[i] < v[i + 1] && v[i] < v[i - 1]) || (v[i] > v[i + 1] && v[i] > v[i - 1]);
			}
			return res;
		};
		int base = solve(a);
		int ans = base;

		for (int i = 0; i < n; ++i) {
			int l = max(0, i - 3), r = min(n, i + 3);
			int ind = i - l;
			vector<int> x(a.begin() + l, a.begin() + r);
			if (i > 0) {
				int cur = base - solve(x);
				x[ind] = a[i - 1];
				cur += solve(x);
				x[ind] = a[i];
				ans = min(ans, cur);
			}
			if (i + 1 < n) {
				int cur = base - solve(x);
				x[ind] = a[i + 1];
				cur += solve(x);
				x[ind] = a[i];
				ans = min(ans, cur);
			}
		}
		cout << ans << "\n";
	}
	return 0;
}