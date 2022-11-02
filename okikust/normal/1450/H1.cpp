#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define N 500100
#define MOD 998244353
#define ll long long
#define rep(i, n) for(ll i = 0; i < n; ++i)
#define rep2(i, a, b) for(ll i = a; i <= b; ++i)
#define rep3(i, a, b) for(ll i = a; i >= b; --i)
#define eb emplace_back
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define vi vector<int>
#define pii pair<int,int>
#define pll pair<ll,ll>


int main(void){
	ll k[N];
	k[0] = 1;
	rep(i, N - 1)k[i + 1] = (k[i] * (i + 1)) % MOD;
	ll r[N];
	bool b[30];
	ll xx = MOD - 2;
	rep(i, 30) {
		if (xx % 2 == 1)b[i] = true;
		else b[i] = false;
		xx /= 2;
	}
	rep(i, N) {
		xx = k[i];
		r[i] = 1;
		rep(j, 30) {
			if (b[j])r[i] = (r[i] * xx) % MOD;
			xx = (xx*xx) % MOD;
		}
	}
	ll n, m;
	ll d2 = (MOD + 1) / 2;
	ll ans = 1;
	ll c[2];
	ll cc;
	ll x[2];
	ll s, ss;
	char a[N];
	rep(i, N)a[i] = 0;
	cin >> n >> m;
	cin >> a;
	rep(i, 2) {
		c[i] = 0;
		x[i] = 0;
	}
	rep(i, n) {
		if (a[i] == 'b')c[(i % 2)]++;
		if (a[i] == '?')x[(i % 2)]++;
	}
	cc = c[1] - c[0];
	rep(i, x[0] + x[1] - 1)ans = (ans*d2) % MOD;
	ss = 0;
	rep2(i, -x[0], x[1]) {
		if ((abs(cc + i)) % 2 == 0) {
			s = k[x[0] + x[1]];
			s = (s*r[x[0] + i]) % MOD;
			s = (s*r[x[1] - i]) % MOD;
			s = (s*((abs(cc + i)) / 2)) % MOD;
			ss = (ss + s) % MOD;
		}
	}
	ans = (ans*ss) % MOD;
	cout << ans << endl;

	return 0;
}