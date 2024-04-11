#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int MOD = 1e9+7;
int binPow(ll b, int p = MOD-2) {
	ll res = 1;
	while(p > 0) {
		if (p & 1) res = res*b%MOD;
		b = b * b % MOD;
		p >>= 1;
	}
	return res;
}

vector<ll> f={1}, iF={1};
ll C(int a, int b) {
	if (a<0||b<0||b>a) return 0;
	assert(a<=(int)5e6);
	while(f.size()<=a) {
		int x=f.size();
		f.push_back(f.back()*x%MOD);
		iF.push_back(iF.back()*binPow(x)%MOD);
	}
	return f[a]*iF[b]%MOD*iF[a-b]%MOD;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, x, pos;
	cin >> n >> x >> pos;
	int small = 0, big = 0;
	int left = 0, right = n;
	while(left < right) {
		int mid = (left + right) / 2;
		if (mid + 1 <= pos + 1) {
			++small;
			left = mid + 1;
		}
		else {
			++big;
			right = mid;
		}
	}
	--small;
	ll ans = 1;
	for (int i = 0; i < big; ++i) {
		ans = ans * (n - x - i) % MOD;
	}
	for (int i = 0; i < small; ++i) {
		ans = ans * (x - 1 - i) % MOD;
	}
	int k = n - small - big - 1;
	for (int i = 1; i <= k; ++i) {
		ans = ans * i % MOD;
	}
	cout << ans;
	return 0;
}