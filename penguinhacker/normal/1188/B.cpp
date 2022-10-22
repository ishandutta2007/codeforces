#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, p, k;
ll a[300000], ans;
map<ll, int> mp;

ll f(ll x) {
	ll res = p - x * k % p;
	x = x * x % p;
	res += x * x;
	return res % p;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> p >> k;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		ans += mp[f(a[i])]++;
	}
	cout << ans;
	return 0;
}