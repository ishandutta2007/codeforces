#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <iterator>
#include <sstream>
#define int long long
#define ld long double
#define debug(x) cout << #x << " is " << x << endl;
using namespace std;
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(7);
	int tt; cin >> tt;
	while (tt--) {
		string s; cin >> s;
		int x, n = s.size(); cin >> x;
		vector <int> ans(n, 1);
		for (int i = 0; i < n; ++i) {
			if (s[i] == '0') {
				if (i >= x) ans[i - x] = 0;
				if (i + x < n) ans[i + x] = 0;
			}
		}
		bool c = true;
		for (int i = 0; i < n; ++i) {
			if (s[i] == '1') {
				int pos = 0;
				if (i >= x) pos = max(pos, ans[i - x]);
				if (i + x < n) pos = max(pos, ans[i + x]);
				if (!pos) c = false;
			}
		}
		if (!c) cout << "-1\n";
		else {
			for (auto x : ans) cout << x;
			cout << '\n';
		}
	}
}