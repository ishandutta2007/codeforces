#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <iomanip>
#include <cassert>
#include <queue>
using namespace std;
#define debug(x) cout << #x << " is " << x << '\n';
#define int long long

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(6);
	int tt; cin >> tt;
	while (tt--) {
		int n; cin >> n;
		string s; cin >> s;
		int m = 0, cur = 0, ans = 0;
		for (auto x : s)
			m += (x == '*');
		for (int i = 0; i < n; ++i) {
			if (s[i] == '*') cur++;
			else {
				int j = i;
				while (j < n and s[j] == s[i])
					j++;
				ans += (j - i) * min(cur, m - cur);
				i = j - 1;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}