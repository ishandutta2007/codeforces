#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
#define pb push_back

ll n, m, t, a;
pll arr[90005];
ll ans[305][305];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	for (int tc=0; tc<t; tc++){
		cin >> n >> m;
		for (int i=0; i<n*m; i++){
			cin >> a;
			arr[i] = mp(a,-i);
		}
		sort(arr,arr+n*m);
		ll cnt = 0;
		ll prev = -1, st = -1, en = -1;
		for (int i=0; i<n*m; i++){
			if (prev != arr[i].first){
				if (prev != -1){
					vector<pll> v;
					for (int j=st; j<=en; j++){
						int row = (j-1)/m, col = (j-1)%m ;
				//		cout << j << " " << row << " " << col << " help \n";
						v.pb(mp(row,-col));
					}
					sort(v.begin(), v.end());
					for (int j=0; j<v.size(); j++){
						ans[v[j].first][-v[j].second] = -arr[en - j - 1].second;
					}
				}
				prev = arr[i].first;
				st = i+1;
				en = i+1;
			}
			else {
				en = i+1;
			}
		}
		vector<pll> v;
		for (int j=st; j<=en; j++){
			int row = (j-1)/m, col = (j-1)%m;
			v.pb(mp(row,-col));
		}
		sort(v.begin(), v.end());
		for (int j=0; j<v.size(); j++){
			ans[v[j].first][-v[j].second] = -arr[en - j - 1].second;
		}
		for (int i=0; i<n; i++){
			for (int j=0; j<m; j++){
			//	cout << ans[i][j] << " ";
				for (int k=0; k<j; k++) if (ans[i][k] < ans[i][j]) cnt++;
			}
	//		cout << "\n";
		}
		cout << cnt << "\n";
	}
}