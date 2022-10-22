#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, q;
string s;
void solve() {
	cin >> n >> q >> s;
	for (int i = 0; i < q; ++i) {
		int l, r; cin >> l >> r, --l, --r;
		bool b = count(s.begin(), s.begin() + l, s[l]) > 0 || count(s.begin() + r + 1, s.end(), s[r]) > 0;
		cout << (b ? "YES" : "NO") << "\n";
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while(t--) solve();
	return 0;
}