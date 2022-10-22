#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, k;
string s;

void solve() {
	cin >> n >> k >> s;
	if (2 * k >= n) {
		cout << "NO\n";
		return;
	}
	int splits = 0;
	for (int i = 0, j = n - 1; i < j; ++i, --j) {
		if (s[i] == s[j])
			++splits;
		else
			break;
	}
	cout << (splits >= k ? "YES" : "NO") << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while(t--)
		solve();
	return 0;
}