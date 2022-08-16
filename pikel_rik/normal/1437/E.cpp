#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;
const int N = 5e5 + 5;

int n, k, a[N], b[N];

int solve(int l, int r) {
	int lwr = a[l - 1] - (l - 1), upr = a[r + 1] - (r + 1);
	vector<int> tail;
	for (int i = l; i <= r; i++) {
		if (a[i] - i < lwr || a[i] - i > upr) continue;
		int idx = upper_bound(tail.begin(), tail.end(), a[i] - i) - tail.begin();
		if (idx == tail.size()) {
			tail.push_back(a[i] - i);
		} else {
			tail[idx] = a[i] - i;
		}
	}
	return r - l + 1 - (int)tail.size();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= k; i++) cin >> b[i];

	b[0] = 0, b[k + 1] = n + 1;
	a[0] = -1e9, a[n + 1] = 1e9 + 1e6;
	k += 2;

	for (int i = 1; i < k; i++) {
		if (a[b[i]] - a[b[i - 1]] < b[i] - b[i - 1]) {
			cout << "-1\n";
			return 0;
		}
	}

	int last = 0, ans = 0;
	for (int i = 1; i <= n + 1; i++) {
		if (binary_search(b, b + k, i)) {
			if (last != i - 1) {
				ans += solve(last + 1, i - 1);
			}
			last = i;
		}
	}
	cout << ans << '\n';
	return 0;
}