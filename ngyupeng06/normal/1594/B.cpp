#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
#define pb push_back

ll n, m, k, t, a, b, c, mod = 1e9+7;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--){
		cin >> a >> b;
		ll s = 1;
		ll sum = 0;
		while (b){
			if (b%2) {
				sum = (sum + s) % mod;
			}
			b /= 2;
			s = (s*a)%mod;
		}
		cout << sum << "\n";
	}
}