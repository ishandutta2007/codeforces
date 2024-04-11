#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
#define pb push_back

ll n, fac[100005], ifac[100005], mod = 998244353;
char x[100005], y[100005];

ll mul_inv(ll a, ll b) { 
	ll b0 = b, t, q, x0 = 0, x1 = 1; 
	if (b == 1) return 1; 
	while (a > 1) { 
		q = a / b; 
		t = b; 
		b = a % b; 
		a = t; 
		t = x0;
		x0 = x1 - q * x0; 
		x1 = t; 
	} 
	if (x1 < 0) x1 += b0; 
	return x1; 
}

ll ncr(ll a, ll b){
	return (fac[a] * ifac[b] % mod) * ifac[a-b] % mod;
}

ll lb, lw, la, rb, rw, ra;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	fac[0] = ifac[0] = 1;
	for (int i=1; i<100005; i++){
		fac[i] = (fac[i-1] * i )% mod;
	//	cout << fac[i] << "\n";
		ifac[i] = mul_inv(fac[i], mod);
	}
	ll gb = 1, gw = 1;
	ll cnt = 1;
	for (int i=0; i<n; i++){
		cin >> x[i] >> y[i];
		if (y[i] == 'B') y[i] = 'W';
		else if (y[i] == 'W') y[i] = 'B';
		if (x[i] == 'B') lb++, gw = 0;
		if (x[i] == 'W') lw++, gb = 0;
		if (x[i] == '?') la++;
		if (y[i] == 'B') rb++, gw = 0;
		if (y[i] == 'W') rw++, gb = 0;
		if (y[i] == '?') ra++;
		if (x[i] == 'B' && y[i] == 'W') cnt = 0;
		if (x[i] == 'W' && y[i] == 'B') cnt = 0;
		else if (x[i] == '?' && y[i] == '?') cnt = cnt * 2 % mod;
	}
	ll ans = 0;
	for (int i=0; i<=n; i++){
		if (i>=lb && i >= rb && i<=n-lw && i<=n-rw){
			ans = (ans + ncr(la, i-lb) * ncr(ra, i-rb) % mod) % mod;
		}
	}
	ans -= cnt;
	ans += 3*mod + gb + gw;
	ans %= mod;
	cout << ans;
}