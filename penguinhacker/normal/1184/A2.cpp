#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	string s; cin >> s;
	int ans = 0;
	vector<int> good(n + 1);
	for (int len = 1; len <= n; ++len) {
		if (n % len == 0) {
			vector<int> cnt(len);
			for (int i = 0; i < n; ++i) cnt[i % len] ^= s[i] == '1';
			good[len] = 1;
			for (int i : cnt) good[len] &= i == 0;
		}
		ans += good[__gcd(n, len)];
	}
	cout << ans;
	return 0;
}