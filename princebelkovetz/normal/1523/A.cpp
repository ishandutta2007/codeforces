#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <iomanip>
#include <string>
using namespace std;
#define debug(x) cout << #x << " is " << x << '\n';
#define ld long double
#define int long long

constexpr int mod = 1e9 + 7;

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(8);
	int tt; cin >> tt;
	while (tt --> 0) {
		int n, m; cin >> n >> m;
		m = min(m, n);
		string s; cin >> s;
		while (m--) {
			string t = s;
			for (int i = 0; i < n; ++i) {
				if (s[i] == '1') t[i] = '1';
				else {
					int cnt = 0;
					if (i and s[i - 1] == '1') cnt++;
					if (i != n - 1 and s[i + 1] == '1') cnt++;
					if (cnt == 1) t[i] = '1';
					else t[i] = '0';
				}
			}
			s = t;
		}
		cout << s << '\n';
	}
}