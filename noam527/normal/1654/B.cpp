#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = 998244353;
const ll inf = 3e18;
const int OO = 1;
using namespace std;

int n;
string s;

void solve() {
	cin >> s;
	n = s.size();
	int c[26] = {};
	for (auto &i : s)
		c[i - 'a']++;
	for (int i = 0; i < n; i++) {
		if (c[s[i] - 'a'] == 1) {
			for (int j = i; j < n; j++)
				cout << s[j];
			cout << '\n';
			return;
		}
		c[s[i] - 'a']--;
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	cin >> tst;
	while (tst--) solve();
}