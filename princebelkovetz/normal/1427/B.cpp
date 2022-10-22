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
#define ull unsigned long long
#define ld long double
#define debug(x) cout << #x << " is " << x << endl;
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(6);
	int tt; cin >> tt;
	while (tt--) {
		int n, k; cin >> n >> k;
		string s; cin >> s;
		vector <pair <int, int>> cntw;
		int ans = 0;
		int left = 0;
		for (int i = 0; i < n; ++i) {
			int j = i;
			if (s[i] != 'W') continue;
			while (j < n and s[j] == 'W')
				++j;
			cntw.push_back({ i, j - i });
			ans += 1 + (j - i - 1) * 2;
			left += j - i;
			i = j;
		}
		left = n - left;
		multiset <int> a;
		for (int i = 1; i < cntw.size(); ++i) {
			a.insert(cntw[i].first - cntw[i - 1].first - cntw[i - 1].second);
		}
		if (!k) {
			cout << ans << '\n';
			continue;
		}
		if (left == n) {
			cout << min(2 * n - 1, 2 * k - 1) << '\n';
			continue;
		}
		while (!a.empty() and *a.begin() <= k) {
			auto it = a.begin();
			ans += *it * 2 + 1;
			k -= *it;
			left -= *it;
			a.erase(it);
		}
		if (k > 0) {
			ans += 2 * min(k, left);
		}
		cout << ans << '\n';
	}
	return 0;
}