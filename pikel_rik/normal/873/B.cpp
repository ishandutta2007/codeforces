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

	int n;
	cin >> n;

	string s;
	cin >> s;

	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		if (s[i] == '1') {
			a[i] = 1;
		} else {
			a[i] = -1;
		}
	}

	map<int, int> mp;
	mp[0] = -1;
	int sum = 0, best = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i];
		if (!mp.count(sum)) {
			mp[sum] = i;
		} else {
			best = max(best, i - mp[sum]);
		}
	}
	cout << best << '\n';
	return 0;
}