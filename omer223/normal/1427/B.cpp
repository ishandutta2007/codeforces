#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, k;
string s;

void solve() {
	int ls = 0;
	cin >> n >> k >> s;
	for (char c : s) {
		if (c == 'L')ls++;
	}
	if (k >= ls) {
		cout << 2 * n - 1 << '\n';
		return;
	}
	else if (ls == n) {
		cout << max(0,2 * k - 1) << '\n';
		return;
	}
	else {
		ll tot = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == 'W') {
				tot++;
				if (i > 0 && s[i - 1] == 'W')tot++;
			}
		}
		vector<pair<bool, int>> v;
		int cr = 0;
		bool pre = 1;
		foru(i, 0, n) {
			if (s[i] == 'L')cr++;
			else {
				if (cr != 0) {
					if (pre == 1) v.pb({ true,cr });
					else v.pb({ false,cr});
				}
				cr = 0;
				pre = 0;
			}
		}
		if (cr != 0)v.pb({ true,cr });
		sort(v.begin(), v.end());
		for (auto x : v) {
			if (k > x.second) {
				tot += (2 * x.second + (!x.first));
				k -= x.second;
			}
			else {
				if (x.first) {
					tot += (2 * k);
					break;
				}
				else {
					if (k == x.second)tot += (2 * k + 1);
					else tot += (2 * k);
					break;
				}
			}
		}
		cout << tot << '\n';
	}
}//LLLL

int main() {
	fast;
	int t;
	cin >> t;
	while (t--)solve();
	return 0;
}