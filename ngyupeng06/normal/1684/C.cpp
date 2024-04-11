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

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while(t--){
		cin >> n >> m;
		int arr[n+2][m+2];
		bool gd = true;
		set<pii> s;
		for (int i=1; i<=n; i++){
			vector<int> v;
			for (int j=1; j<=m; j++){
				cin >> arr[i][j];
				v.pb(arr[i][j]);
			}
			sort(all(v));
			ll cnt = 0;
			vector<int> vv;
			for (int j=1; j<=m; j++){
				if (arr[i][j] != v[j-1]){
					cnt++;
					vv.pb(j);
				}
			}
			if (cnt > 2) gd = false;
			else if (cnt == 2){
				s.insert(mp(vv[0], vv[1]));
			}
		}
		if (!gd || s.size() > 1){
			cout << -1 << nl;
		}
		else if (s.size() == 0){
			cout << "1 1\n";
		}
		else {
			auto it = s.begin();
			ll x = (*it).first, y = (*it).second;
			//cout << x << " " << y << " debug\n";
			for (int i=1; i<=n; i++){
				swap(arr[i][x], arr[i][y]);
				for (int j=1; j<m; j++){
					if (arr[i][j] > arr[i][j+1]) gd = false;
				}
			}
			if (!gd) cout << "-1\n";
			else cout << x << " " << y << nl;
		}
	}
}