#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;

	string s; cin >> s;
	string t = s;
	reverse(begin(t), end(t));

	cout << ((k == 0 || s == t) ? 1 : 2) << '\n';
}

int main() {
	int tc; cin >> tc;
	while (tc--) solve();
}