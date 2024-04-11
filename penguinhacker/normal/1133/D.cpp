#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	int ans = 0;
	map<pair<int, int>, int> mp;
	vector<int> a(n); for (int& i : a) cin >> i;
	vector<int> b(n); for (int& i : b) cin >> i;
	for (int i = 0; i < n; ++i) {
		if (a[i] == 0) {
			ans += b[i] == 0;
			continue;
		}
		if (b[i] == 0) ++mp[{1, 0}];
		else {
			int g = __gcd(abs(a[i]), abs(b[i]));
			a[i] /= g, b[i] /= g;
			if (b[i] < 0) a[i] *= -1, b[i] *= -1;
			++mp[{a[i], b[i]}];
		}
	}
	int mx = 0;
	for (auto& x : mp) {
		//cout << x.first.first << " " << x.first.second << " " << x.second << "\n";
		mx = max(mx, x.second);
	}
	ans += mx;
	cout << ans;
	return 0;
}