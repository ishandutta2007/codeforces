#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>

using namespace std;
#define debug(x) cout << #x << " is " << x << '\n';
#define ld long double
#define int long long

const int mod = 1e9 + 7;
int gcd(int a, int b) {
	if (!b) return a;
	return gcd(b, a % b);
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int tt; cin >> tt;
	while (tt --> 0) {
		int n; cin >> n;
		string s; cin >> s;
		string ans = "";
		for (char i = 'a'; i <= 'z' and ans.empty(); ++i) {
			bool c = true;
			for (int x = 0; x < n; ++x) {
				if (s[x] == i) c = false;
			}
			if (c) ans += (char)i;
		}
		for (char i = 'a'; i <= 'z' and ans.empty(); ++i) {
			for (char j = 'a'; j <= 'z' and ans.empty(); ++j) {
				bool c = true;
				for (int x = 0; x < n - 1; ++x) {
					if (s[x] == i and s[x + 1] == j) c = false;
				}
				if (c) {
					ans += i;
					ans += j;
				}
			}
		}
		for (char i = 'a'; i <= 'z' and ans.empty(); ++i) {
			for (char j = 'a'; j <= 'z' and ans.empty(); ++j) {
				for (char k = 'a'; k <= 'z' and ans.empty(); ++k) {
					bool c = true;
					for (int x = 0; x < n - 2; ++x) {
						if (s[x] == i and s[x + 1] == j and s[x + 2] == k) c = false;
					}
					if (c) {
						ans += i;
						ans += j;
						ans += k;
					}
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}