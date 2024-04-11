#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <stack>
#include <map>
#include <queue>
#include <iterator>
#include <sstream>
#include <cassert>
#include <locale>
#define int long long
#define ull unsigned long long
#define ld long double
#define debug(x) cout << #x << " is " << x << endl;
using namespace std;
const int mod = 1e9 + 7;
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(7);
	vector <int> a(6);
	for (auto& x : a)
		cin >> x;
	int n; cin >> n;
	vector <int> b(n);
	for (auto& x : b) cin >> x;
	vector <pair <int, int>> c;
	for (int i = 0; i < n; ++i) {
		for (auto x : a)
			c.push_back({ b[i] - x, i });
	}
	vector <int> cnt(n), left(6 * n, -1);
	sort(c.begin(), c.end());
	int sum = 0;
	for (int i = 0; i < 6 * n; ++i) {
		if (sum != n) {
			int j = max(i, left[i] + 1);
			for (; j < 6 * n; ++j) {
				if (!cnt[c[j].second])
					++sum;
				cnt[c[j].second]++;
				if (sum == n) break;
			}
			left[i] = j;
		}
		if (i < 6 * n - 1) left[i + 1] = left[i];
		cnt[c[i].second]--;
		if (!cnt[c[i].second])
			sum--;
	}
	int ans = 1e9 + 7;
	for (int i = 0; i < 6 * n; ++i) {
		if (left[i] >= 6 * n) break;
		ans = min(ans, c[left[i]].first - c[i].first);
	}
	cout << ans << '\n';
	return 0;
}