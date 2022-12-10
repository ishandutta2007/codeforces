#include <bits/stdc++.h>

using namespace std;

#define pow Pow

typedef long long int ll;

const int maxn = 1e5 + 10;
ll D = 1e9 + 7;
ll s[maxn], P[maxn], a[maxn];

ll pow(ll a, ll b){
	if(b == 0)
		return 1;
	ll x = pow(a, b / 2);
	x *= x;
	x %= D;
	if(b % 2 == 1)
		x *= a;
	return x % D;
}

ll dev(ll a, ll b){
	return (a * pow(b, D - 2)) % D;
}

ll C(ll n, ll r){
	if(r > n or r < 0)
		return 0;
	r = max(r, n - r);
	ll ans = 1;
	for(ll i = r + 1; i <= n; i++){
		ans *= i;
		ans %= D;
		ans = dev(ans, i - r);
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	ll n, k;
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		char c;
		cin >> c;
		a[i] = c - '0';
	}
	reverse(a, a + n);
	for(int i = n - 2; i >= 0; i--)
		s[i] = s[i + 1] + a[i + 1];
	P[0] = 1;
	for(int i = 1; i <= n; i++){
		P[i] = P[i - 1] * 10;
		P[i] %= D;
	}
	/*ll kk = C(n - 1, k), kkm1 = (C(n - 2, k - 1));
	ll up1 = n - 1, up2 = n - 2;
	ll ans = 0;
	for(int i = 0; i < n; i++){
		if(n - 2 - i >= k - 1) ans += (kkm1 * s[i] * P[i]) % D;
		ans %= D;
		if(n - 1 - i >= k) ans += (kk * a[i] * P[i]) % D;
		ans %= D;
		kk *= up1 - k;
		kk %= D;
		kk = dev(kk, up1);
		kkm1 *= up2 - k + 1;
		kkm1 %= D;
		kkm1 = dev(kkm1, up2);
		up1--, up2--;
	}*/
	ll S = 0;
	ll kk = C(n - 1, k), kkm1 = C(n - 2, k - 1);
	ll up1 = n - 1, up2 = n - 2;
	ll ans = 0;
	for(int i = 0; i < n; i++){
		ans += (S + kk * P[i]) * a[i];
		ans %= D;
		
		S += kkm1 * P[i];
		S %= D;
		
		kk *= up1 - k;
		kk %= D;
		kk = dev(kk, up1);
		
		kkm1 *= up2 - k + 1;
		kkm1 %= D;
		kkm1 = dev(kkm1, up2);
		
		up1--, up2--;
	}
	cout << ans << endl;
	return 0;
}