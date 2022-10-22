#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
#define pb push_back
#define nl "\n"
#define all(v) v.begin(),v.end()

ll n, m, t;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while(t--){
		cin >> n;
		ll a, b = -1, c1 = 1e9, c2 = -1;
		for (ll i=0; i<n; i++){
			cin >> a;
			if (a == b){
				c1 = min(c1, i);
				c2 = max(c2, i);
			}
			b = a;
		}
		if (c1 == 1e9) cout << "0\n";
		else if (c2 - c1 == 0) cout << "0\n";
		else if (c2 - c1 == 1) cout << "1\n";
		else cout << c2-c1-1 << "\n";
	}
}