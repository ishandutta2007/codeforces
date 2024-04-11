#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int MOD = 998244353;
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

int n, a[300000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < 2 * n; ++i) cin >> a[i];
	sort(a, a + 2 * n);
	ll ans = accumulate(a + n, a + 2 * n, 0ll) - accumulate(a, a + n, 0ll);
	ans %= MOD;
	ans = ans * C(2 * n, n) % MOD;
	cout << ans;
	return 0;
}