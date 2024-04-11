#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <queue>
#include <iomanip>

using namespace std;

#define debug(x) cout << #x << " is " << x << '\n';
#define ld long double
#define int long long

const int mod = 1e9 + 7;

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(8);
	int tt; cin >> tt;
	while (tt --> 0) {
		string s; cin >> s;
		int n = s.size(), id = -1;

		for (int i = 0; i < n; ++i) {
			if (s[i] == 'a') id = i;
		}
		int l = id, r = id;
		char cur = 'b';
		while (l > 0 or r < n - 1 and id != -1) {
			if (l and s[l - 1] == cur) l--;
			else if (r < n - 1 and s[r + 1] == cur)r++;
			else break;
			cur++;
		}
		cout << (l == 0 and r == n - 1 ? "YES" : "NO") << '\n';
	}
	return 0;
}