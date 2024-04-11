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

	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	set<pair<int, int>> ans;

	for (int i = 2; i < n; i++) {
		int lim = 1 << (32 - __builtin_clz(a[i]));
		ll sum = a[i - 1];
		for (int j = i - 2; j >= 0 && sum < lim; j--) {
			if ((a[i] ^ a[j]) == sum) {
				ans.emplace(j, i);
			}
			sum += a[j];
		}
	}

	for (int i = 0; i < n - 2; i++) {
		int lim = 1 << (32 - __builtin_clz(a[i]));
		ll sum = a[i + 1];
		for (int j = i + 2; j < n && sum < lim; j++) {
			if ((a[i] ^ a[j]) == sum) {
				ans.emplace(i, j);
			}
			sum += a[j];
		}
	}

	cout << ans.size() << '\n';
	return 0;
}