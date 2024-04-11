#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
#define pb push_back

ll n, m, k, t, a, b, c, arr[200005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--){
		cin >> n;
		vector<ll> v;
		for (int i=0; i<n; i++){
			cin >> a;
			v.pb(a);
		}
		ll ans = 1;
		for (int i=0; i<n; i++){
			if (i && v[i-1] == v[i]) continue;
			ll cur = 1;
			ll cnt = i+1;
			while (cnt < n && v[cnt] == v[i]){
				cur++;
				cnt++;
			} 
			if (cnt < n){
				cur++;
				ll cr = v[cnt];
				while (true){
				//	cout << i << " " << cr << "\n";
					ll x = cr - v[i];
					auto y = lower_bound(v.begin(), v.end(), cr + x);
					if (y != v.end()){
						ll Y = y - v.begin();
						cr = v[Y];
						cur++;
					}
					else break;
				}
			}
			ans = max(ans, cur);
		}
		cout << n - ans << "\n";
	}
}