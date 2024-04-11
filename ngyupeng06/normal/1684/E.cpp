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
map<ll, ll> cnt;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--){
		cin >> n >> m;
		ll a;
		cnt.clear();
		vector<int> v;
		ll d = 0;
		for (int i=0; i<n; i++){
			cin >> a;
			if (cnt[a] == 0) d++;
			cnt[a]++;
			v.pb(a);
		}
		sort(all(v));
		ll sum = 0, cmax = 0, csum = 0;
		for (int i=0; i<n; i++){
			if (cnt[i] == 0){
				sum++;	
			}
			if (sum <= m){
				cmax = i+1;
				csum = sum;
			}
		}
		vector<int> vv;
		for (int i=0; i<n; i++){
			if (v[i] < cmax) continue;
			else if (i > 0 && v[i] == v[i-1]) continue;
			vv.pb(cnt[v[i]]);
		}
		sort(all(vv));
		d += csum;
		for (auto it: vv){
			if (it <= m){
				m -= it;
				d--;
			}
		}
		//cout << d << " " << cmax << nl;
		cout << d - cmax << nl;
	}
}