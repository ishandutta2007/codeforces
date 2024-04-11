#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
#define pb push_back

ll n, m, k, t, a, b, c, arr[40], mod = 1e9+7;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	ll ans = 1;
	for (int i=0; i<n; i++){
		ans *= 2;
		ans %= mod;
		cin >> a;
		ll cnt = 0;
		while (a%2 == 0){
			cnt++;
			a/=2;
		}
		arr[cnt]++;
	}
	ans += mod - 1;
	ans %= mod;
	ll x = n - arr[0];
	ll thing = 1;
	for (int i=40; i>0; i--){
		if (arr[i] == 0) continue;
		ll thingy = 1;
		for (int j=0; j<arr[i]-1; j++){
			thingy *= 2;
			thingy %= mod;
		}
		ll y = thingy * thing % mod;
		ans += mod - y;
		ans %= mod;
		thing *= thingy * 2;
		thing %= mod;
	}
	cout << ans << "\n";
}