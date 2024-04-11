#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define nl "\n"
#define all(v) v.begin(),v.end()

ll n, m, t;
ll mod = 1e9+7;
ll fac[500005], ifac[500005];

ll mi(ll x){
	ll cur = x;
	ll sum = 1;
	ll mm = mod - 2;
	while (mm){
		if (mm%2){
			sum = sum * cur % mod;
			
		}
		mm /= 2;
		cur = cur * cur % mod;
	}
	return sum;
}

ll ncr(ll x, ll y){
	if (x == 0) return 0;
	if (y == 0) return 1;
	return fac[x] * ifac[y] % mod * ifac[x-y] % mod;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	fac[0] = ifac[0] = 1;
	for (int i=1;i<=500005; i++){
		fac[i] = fac[i-1] * i % mod;
		ifac[i]=mi(fac[i]);
	}
	cin >> n;
	ll ans = 0;
	for (int i=0; i<n+1; i++){
		ll a;
		cin >> a;
		ans += ncr(a+i, i+1);
		ans %= mod;
	}
	cout << ans;
}