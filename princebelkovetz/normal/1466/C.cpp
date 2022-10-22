#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cassert>
#include <map>
#include <set>
using namespace std;
#define debug(x) cout << #x << " is " << x << '\n';
#define int long long
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(6);
	int testcases; cin >> testcases;
	int rnd = 0;
	while (testcases --> 0) {
		string s; cin >> s;
		int n = s.size();
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			if (i < n - 2 and s[i] == s[i + 1] and s[i] == s[i + 2]) {
				ans += 2;
				s[i + 1] = ('0' + rnd);
				rnd = (rnd + 1) % 10;
				s[i + 2] = ('0' + rnd);
			}
			if (i < n - 2 and s[i] == s[i + 2]) {
				s[i + 2] = ('0' + rnd);
				ans++;
			}
			if (i < n - 1 and s[i] == s[i + 1]) {
				ans++;
				s[i + 1] = ('0' + rnd);
			}
			rnd = (rnd + 1) % 10;
		}
		cout << ans << '\n';
	}
}