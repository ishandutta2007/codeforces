#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <queue>
#include <string>

using namespace std;
#define debug(x) cout << #x << " is " << x << '\n';
#define ld long double
#define int long long

const int mod = 1e9 + 7, N = 1e5 + 2;

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int tt; cin >> tt;
	while (tt--) {
		int n; cin >> n;
		string s; cin >> s;
		int mn = n / 2;
		bool ok = false;
		for (int i = mn; i < n and !ok; ++i) {
			if (s[i] == '0') {
				ok = true;
				cout << "1 " << i + 1 << " 1 " << i << '\n';
			}
		}
		for (int i = 0; i + mn < n and !ok; ++i) {
			if (s[i] == '0') {
				ok = true;
				cout << i + 1 << ' ' << n << ' ' << i + 2 << ' ' << n << '\n';
			}
		}
		if (!ok) {
			cout << "1 " << mn << " 2 " << mn + 1 << '\n';
		}
	}
	
	return 0;
}