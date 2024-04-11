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
ll cnt[200005];
ll ans[200005];
ll arr[200005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while(t--){
		cin >> n;
		vector<pll> v;
		for (int i=1; i<=n; i++) cnt[i] = 0;
		ll cmax = 0;
		for(int i=0;i<n;i++){
			cin >> arr[i];
			cnt[arr[i]]++;
			cmax = max(cmax, cnt[arr[i]]);
			v.pb(mp(arr[i],i));
		}
		sort(all(v));
		
		for (int i=0; i<n; i++){
			ans[v[(i+cmax)%n].second] = v[i].first;
		}
		
		for (int i=0; i<n; i++){
			cout << ans[i] << " ";
		}
		cout << "\n";
	}
}