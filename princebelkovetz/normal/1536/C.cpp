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
		map <pair <int, int>, int> last;
		vector <int> ans(n);
		int k = 0, d = 0;
		for (int i = 0; i < n; ++i) {
			if (s[i] == 'K') k++;
			else d++;
			if (d and k) {
				if (last.find({ d / gcd(d, k), k / gcd(d, k) }) != last.end())
					ans[i] += ans[last[{ d / gcd(d, k), k / gcd(d, k) }]];
				ans[i]++;
				last[{ d / gcd(d, k), k / gcd(d, k) }] = i;
			}
			else {
				ans[i] = i + 1;
			}
		}
		for (auto x : ans) cout << x << ' ';
		cout << '\n';
	}
	return 0;
}