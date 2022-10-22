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
ll arr[200005];
	
vector<pll> v1[200005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--){
		cin >> n >> m;
		for (int i=0; i<n; i++){
			cin >> arr[i];
			v1[i].clear();
		}
		ll a = n;
		vector<ll> p;
		for (ll i=2; i*i <= a; i++){
			if (a%i == 0){
				p.pb(i);
				while (a%i == 0){
					a /= i;
				}
			}
		}
		if (a > 1) p.pb(a);
		ll cnt = 0;
		multiset<ll> s;
		vector<ll> v;
		for (int i=0; i<p.size(); i++){
			ll x = p[i];
			ll y = n/x;
			for (int j=0; j<y; j++){
				ll sum = 0;
				for (int k=0; k<x; k++){
					ll A = j + y*k;
					v1[A].pb(mp(cnt, y));
					sum += arr[A];
				}
				sum *= y;
				v.pb(sum);
				cnt++;
				s.insert(sum);
			}

		}
		multiset<ll>::iterator it;
		it = s.end();
		it--;
		cout << *it << nl;
		for (int i=0; i<m; i++){
			ll b, c;
			cin >> b >> c;
			b--;
			for (int j=0; j<v1[b].size(); j++){
				ll x = v1[b][j].first, y = v1[b][j].second;
				ll su = v[x];
		//		cout << v[x] << "test ";
				s.erase(s.find(su));
				v[x] = su + y*(c-arr[b]);
		//		cout << v[x] << nl;
				s.insert(v[x]);
				
			}
			arr[b] = c;
			it = s.end();
			it--;
			cout << *it << nl;
		}
	}
}