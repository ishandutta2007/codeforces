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

ll n, m, t, a, b, c;
ll arr[100005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i=0; i<n; i++) {
			cin >> arr[i];
		}
		vector<pll> v;
		
		for (int i=1; i<n; i++){
			if (arr[i] < arr[i-1]) {
				v.pb(mp(arr[i-1]-arr[i], i+1));
			}
		}
		
		sort(all(v));
		ll sz=  v.size();
		vector<ll> ans;
		for (int i=sz-1; i>=0; i--) {
			ll x = v[i].second;
			ans.pb(x);
		}
		for (int i=0; i<n-sz; i++){
			ans.pb(n);
		}
		for (int i  =n-1; i>=0; i--){
			cout << ans[i] << " ";
			
		}
		cout << nl;
	}
}