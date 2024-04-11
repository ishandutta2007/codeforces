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
ll arr[200006];
map<int, deque<int> > ma;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--){
		cin >> n >> m;
		ma.clear();
		for (int i=1; i<=n; i++){
			cin >> arr[i];
		}
		vector<pii> v;
		for (int i=1; i<=m; i++){
			ll a, b;
			cin >> a >> b;
			v.pb(mp(b,a));
		}
		sort(all(v));
		deque<pii> dq;
		for (int i=0; i<m; i++){
			while (!dq.empty() && dq.back().first >= v[i].second){
				dq.pop_back();
			}
			dq.push_back(mp(v[i].second, v[i].first));
		}
		int sz = dq.size();
		int l = -1, r = -1;
		vector<pii> vv;
		ll cmin = 1e9, cmax = -1;
		for (int i = 0; i < sz; i++){
			int a, b;
			a = dq[i].first, b = dq[i].second;
			if (a > r){
				l = a, r = a-1;
				ma.clear();
			}
			while (l < a){
				ma[arr[l]].pop_front();
				l++;
			}
			for (int j=r+1; j<=b; j++){
				ma[arr[j]].pb(j);
				if (ma[arr[j]].size() >= 2){
					vv.pb(mp(ma[arr[j]].front(), ma[arr[j]].back()));
					cmin = min(cmin, (ll)ma[arr[j]][1]);
					cmax = max(cmax, (ll)ma[arr[j]][ma[arr[j]].size()-2]);
				}
			}
			r = b;
		}
		if (cmin == 1e9){
			cout << 0 << nl;
			continue;
		}
		sort(all(vv));
		ll curr = cmax;
		ll ans = 1e9;
		for (auto it : vv){
			ans = min(ans, curr - min(cmin,(ll)it.first) + 1);
			curr = max(curr, (ll)it.second);
		}
		ans = min(ans, curr - cmin + 1);
		if (ans == 1e9) cout << 0 << nl;
		else cout << ans << nl;
	}

	
}