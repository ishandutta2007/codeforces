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

ll n, m, t, arr[50005], b[50005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while(t--){
		cin >> n >> m;
		vector<pll> v, v1;
		for (int i=0; i<n; i++){
			cin >> arr[i];
			ll cur = 1;
			while (arr[i] % m == 0){
				cur *= m;
				arr[i] /= m;
			}
			if (!v.empty() && v.back().first == arr[i]){
				v.back().second += cur;
			}
			else {
				v.pb(mp(arr[i], cur));
			}
		}
		ll k;
		cin >> k;
		for (int i=0; i<k; i++){
			cin >> b[i];
			ll cur = 1;
			while (b[i] % m == 0){
				cur *= m;
				b[i] /= m;
			}
			if (!v1.empty() && v1.back().first == b[i]){
				v1.back().second += cur;
			}
			else {
				v1.pb(mp(b[i], cur));
			}
		}
		if (v.size() != v1.size()){
			cout << "No\n";
		}
		else {
			bool gd= true;
			for (int i=0; i<v.size(); i++){
				if (v[i] != v1[i]){
					gd = false;
				}
			}
			if (gd){
				cout << "Yes\n";
		
			}
			else cout << "No\n";
		}
	}
}