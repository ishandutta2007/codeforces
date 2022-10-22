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

ll n, m, q, k, t, a, b, c;
ll arr[100005];
ll cmin[100005], cmax[100005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		cmin[0] = 1e9, cmax[n+1] = -1;
		vector<int> v[n+1];
		for (int i = 1; i<=n; i++) {
			cin >> arr[i];
			if (arr[i] == 0 || arr[i] == n+1) {
				v[0].pb(i);
			}
			else {
				v[arr[i]].pb(i);
			}
			cmin[i] = min(arr[i], cmin[i-1]);
		}
		for (int i = n; i >= 1; i--) {
			cmax[i] = min(arr[i], cmax[i+1]);
		}
		ll k;
		for (int i = 0; i <= n; i++){
			if (cmin[i] > i && cmax[i+1] <= i) k = i;
		}	
		vector<int> ans;
		ll cur = 0;
		while (true) {
			ll x = -1;
			for (auto it : v[cur]){
				if (v[it].size()) x = it;
				else {
					ans.pb(it);
				}
			}
			if (x != -1){
				ans.pb(x);
				cur = x;
			}
			else break;
		}
		cout << k << nl;
		for (auto it : ans) cout << it << " ";
		cout << nl;
	}

}