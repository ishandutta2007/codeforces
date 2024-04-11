#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
#define pb push_back
#define nl "\n"
#define all(v) v.begin(),v.end()

ll n, m, t, mod = 998244353;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while(t--){
		cin >> n >> m;
		ll ans=1;
		for (int i=0; i<n-m; i++){
			ll a;
			cin >> a;
			if (a == -1){
				ans *= (i + m+1);
				ans %= mod;
			}
			else if (a == 0){
				ans *= (m+1);
				ans %= mod;
			}
		}
		for (int i=n-m; i<n; i++){
			ll a;
			cin >> a;
			if (a > 0) ans = 0;
			else {
				ans *= ((n-m)-i+m);
				ans %= mod;
			}
		}
		cout << ans << nl;
	}
}