#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 998244353;
const ll inf = 2e18;
const int OO = 1;
const int OOO = 1;
using namespace std;

string s;
int n;
vector<int> even, odd;

void solve() {
	cin >> s;
	n = s.size();
	if (n <= 2) {
		if (n == 1) cout << s << '\n';
		else {
			if (s[0] == s[1]) cout << s << '\n';
			else cout << s[0] << '\n';
		}
		return;
	}
	int p = 0;
	while (p < n && s[p] == s[n - 1 - p]) p++;
	if (p == n) {
		cout << s << '\n';
		return;
	}
	
	even.clear(), odd.clear();
	even.resize(n - 1, 0), odd.resize(n, 1);

	for (int i = 1, c = 0, r = 0; i < n; i++) {
		if (i <= r) odd[i] = min(r - i + 1, odd[2 * c - i]);
		while (i - odd[i] >= 0 && i + odd[i] < n && s[i - odd[i]] == s[i + odd[i]])
			odd[i]++;
		if (i + odd[i] - 1 > r) {
			r = i + odd[i] - 1;
			c = i;
		}
	}

	for (int i = 0, c = -1, r = -1; i < n - 1; i++) {
		if (i < r) even[i] = min(r - i, even[2 * c - i]);
		while (i - even[i] >= 0 && i + even[i] + 1 < n && s[i - even[i]] == s[i + even[i] + 1]) even[i]++;
		if (i + even[i] > r) {
			r = i + even[i];
			c = i;
		}
	}

	bool od = true;
	int mx = 0, pos = 0;
	for (int i = p; i <= n - 1 - p; i++) {
		if (i - odd[i] < p || i + odd[i] > n - 1 - p) {
			if (mx < 2 * min(i - p + 1, n - p - i) - 1) {
				mx = 2 * min(i - p + 1, n - p - i) - 1;
				od = true;
				pos = i;
			}
		}
	}
	for (int i = p; i <= n - 2 - p; i++) {
		if (i - even[i] < p || i + even[i] + 1 > n - 1 - p) {
			if (mx < 2 * min(i - p + 1, n - 1 - p - i)) {
				mx = 2 * min(i - p + 1, n - 1 - p - i);
				od = false;
				pos = i;
			}
		}
	}
	string ans = "";
	for (int i = 0; i < p; i++) ans.push_back(s[i]);
	if (mx != 0) {
		if (od) {
			for (int i = pos - mx / 2; i <= pos + mx / 2; i++)
				ans.push_back(s[i]);
		}
		else {
			for (int i = pos - mx / 2 + 1; i <= pos + mx / 2; i++)
				ans.push_back(s[i]);
		}
	}
	for (int i = n - p; i < n; i++) ans.push_back(s[i]);
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int t = 1;
	cin >> t;
	while (t--) solve();
}