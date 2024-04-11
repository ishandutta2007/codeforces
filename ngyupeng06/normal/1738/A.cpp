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

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--) {
		ll cnt[2];
		cnt[0] = cnt[1] = 0;
		ll sum = 0;
		cin >> n;
		for (int i = 0; i<n; i++) {
			cin >> arr[i];
			cnt[arr[i]]++;
		}
		vector<ll> v[2];
		for (int i = 0; i<n; i++) {
			cin >> b;
			v[arr[i]].pb(b);
			sum += b;
		}
		sort(v[0].begin(), v[0].end());
		sort(v[1].begin(), v[1].end());
		
		ll sz = v[0].size(), sz1 = v[1].size();
		
		ll m = min(sz, sz1);
		
		for (int i = sz - 1; i >= sz - m; i--){
			sum += v[0][i];
		}
		
		for (int i = sz1 - 1; i >= sz1 - m; i--){
			sum += v[1][i];
		}
		
		if (cnt[0] == cnt[1]) {
			sum -= min(v[0][sz - m], v[1][sz1 - m]);
		}
		cout << sum << nl;
	}
}