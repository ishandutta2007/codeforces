#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;
const int N = 2e5 + 5;

int recurse(const vector<unsigned int> &a) {
	int n = int(a.size());
	if (n <= 2) {
		return 0;
	}

	int zero = 0;
	vector<vector<unsigned int>> cnt(30);
	for (int i = 0; i < n; i++) {
		if (a[i]) {
			cnt[32 - __builtin_clz(a[i]) - 1].push_back(a[i]);
		} else {
			zero++;
		}
	}

	int ans = n - 2;
	int sum = 0;
	for (int i = 0; i < 30; i++) {
		if (cnt[i].empty()) continue;
		sum += (int) cnt[i].size() - 1;
	}

	int cur = zero;
	for (int i = 0; i < 30; i++) {
		if (cnt[i].empty()) continue;
		sum -= (int) cnt[i].size() - 1;
		for (auto& item : cnt[i]) {
			item ^= (1 << i);
		}
		ans = min(ans, recurse(cnt[i]) + sum + max(0, cur - 1));
		cur += cnt[i].size();
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<unsigned int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	cout << recurse(a) << '\n';
	return 0;
}