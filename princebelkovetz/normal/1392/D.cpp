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
	cout << fixed << setprecision(4);
	int tt; cin >> tt;
	while (tt--) {
		int n; cin >> n;
		string s; cin >> s;
		vector <int> l, r;
		for (int i = 0; i < n; ++i) {
			int j = i;
			while (j < n and s[j] == s[i]) ++j;
			if (s[i] == 'L') l.push_back(j - i);
			if (s[i] == 'R') r.push_back(j - i);
			i = j - 1;
		}
		if (s[n - 1] == s[0] and !l.empty() and !r.empty()) {
			if (s[0] == 'L') {
				l[0] += l.back();
				l.pop_back();
			}
			if (s[0] == 'R') {
				r[0] += r.back();
				r.pop_back();
			}
		}
		int ans = 0;
		for (auto x : l) {
			ans += x / 3;
		}
		for (auto x : r) ans += x / 3;
		if (r.empty()) ans = (l[0] - 1) / 3 + 1;
		if (l.empty()) ans = (r[0] - 1) / 3 + 1;
		cout << ans << '\n';
	}
}