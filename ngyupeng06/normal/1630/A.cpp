#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
#define pb push_back

ll n, m, t;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--){
		cin >> n >> m;
		if (m == 0){
			ll x = n-1;
			for (ll i=0; i<n/2; i++){
				ll a = x ^ i;
				cout << i << " " << a << "\n";
			}
		}
		else if (m == n-1){
			if (n == 4) cout << -1 << "\n";
			else {
				cout << n-1 << " " << n-2 << "\n";
				cout << 1 << " " << 3 << "\n";
				ll b = 3 ^ (n-1);
				cout << 0 << " " << b << "\n";
				ll x = n-1;
				for (ll i=0;i<n/2; i++){
					if (i == 0 || i == 1 || i == 3) continue;
					ll a = x ^ i;
					cout << i << " " << a << "\n";
				}
			}
		}
		else {
			cout << m << " " << n-1<< "\n";
			ll b = m ^ (n-1);
			cout << 0 << " " << b << "\n";
			ll x = n-1;
			for (ll i=0; i<n/2; i++){
				if (i == 0 || i == m || i == (m ^ (n-1))) continue;
				ll a= x^i;
				cout << i << " " << a << "\n";
			}
		}
	}
}