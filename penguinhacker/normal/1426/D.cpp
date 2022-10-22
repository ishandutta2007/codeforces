#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, a[200000];
map<ll, int> mp;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	mp[0] = -1;
	ll pre = 0;
	int last = -1;
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		pre += a[i];
		if (mp.find(pre) != mp.end()) {
			if (last <= mp[pre] + 1) {
				last = i;
				++ans;
			}
		}
		mp[pre] = i;
	}
	cout << ans;
	return 0;
}