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
	int n;
	cin >> n;
	ll ans = C(n - 1, n / 2 - 1);
	ans *= f[n / 2 - 1] * f[n / 2 - 1];
	cout << ans;
	return 0;
}