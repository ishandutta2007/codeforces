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
ll arr[2005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i=0; i<n; i++) {
			cin >> arr[i];
		}
		if (n==1){
			cout << 0 << nl;
			continue;
		}
		
		ll cmin = 1e9, cmax = -1e9;
		for (int i=0; i<n-1; i++){
			cmin = min(arr[i], cmin);
		}
		for (int i=1; i<n; i++){
			cmax = max(arr[i], cmax);
		}
		ll ans = -1e9;
		for (int i=0;i<n; i++){
			ans = max(ans, arr[i] - arr[(i+1)%n]);
		}
		
		cout << max(arr[n-1] - cmin, max(cmax - arr[0], ans) )<< nl;
	}
}