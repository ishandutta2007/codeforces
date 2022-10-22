#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, k, c1[26], c2[26];
string a, b;
void solve() {
	memset(c1, 0, sizeof(c1));
	memset(c2, 0, sizeof(c2));
	cin >> n >> k >> a >> b;
	for (int i = 0; i < n; ++i) {
		++c1[a[i] - 'a'];
		++c2[b[i] - 'a'];
	}
	for (int i = 0; i < 25; ++i) {
		if (c2[i] > c1[i]) {cout << "No\n"; return;}
		if ((c1[i] - c2[i]) % k > 0) {cout << "No\n"; return;}
		c1[i + 1] += c1[i] - c2[i];
	}
	cout << "Yes\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while(t--) solve();
	return 0;
}