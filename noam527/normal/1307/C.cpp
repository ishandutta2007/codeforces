#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 4e18;
const int OO = 1;
const int OOO = 1;
using namespace std;

void solve() {
	int n;
	string s;
	cin >> s;
	n = s.size();
	ll ans = 0;
	for (char st = 'a'; st <= 'z'; st++) {
		ll cnt = 0;
		ll P[26] = {};
		for (int i = 0; i < n; i++) {
			if (s[i] == st)
				cnt++;
			else {
				P[s[i] - 'a'] += cnt;
			}
		}
		ans = max(ans, (cnt * (cnt - 1)) / 2);
		ans = max(ans, cnt);
		for (int i = 0; i < 26; i++)
			ans = max(ans, P[i]);
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int t;
	t = 1;
	while (t--) solve();
}