#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int convert(string s) {
	int res = 0;
	for (char c : s) res ^= 1 << (c - 'a');
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	map<int, int> mp;
	for (int i = 0; i < n; ++i) {
		string s; cin >> s;
		++mp[convert(s)];
	}
	ll ans = 0;
	for (auto& x : mp) {
		int cur = x.second - 1;
		for (int i = 0; i < 26; ++i)
			if (mp.find(x.first ^ (1 << i)) != mp.end()) cur += mp[x.first ^ (1 << i)];
		ans += (ll)x.second * cur;
	}
	assert(ans % 2 == 0);
	ans /= 2;
	cout << ans;
	return 0;
}