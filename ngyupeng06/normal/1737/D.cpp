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
ll dist[505][505];
ll dist1[505];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i=0; i<=n; i++){
			dist1[i] = 1e18;
			for (int j=0; j<=n; j++){
				dist[i][j] = 1e9;
			}
		}
		for (int i =0; i<=n; i++){
			dist[i][i] = 0;
		}
		vector<pair<pll, ll> > e;
		for (int i=0; i<m; i++) {
			cin >> a >> b >> c;
			e.pb(mp(mp(a,b), c));
			dist[a][b] = dist[b][a] = 1;
		}
		for (int k=1; k<=n; k++){
			for (int i=1; i<=n; i++){
				for (int j=1; j<=n; j++){
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		}
		ll ans = 1e18;
		
		for (int i=1; i<=n; i++){
			for (int j=1; j<=n; j++){
				dist1[i] = min(dist1[i], dist[i][j]+dist[j][1]+dist[j][n]);
			}
		}
		
		for (auto it : e){
			ll x = it.second;
			ll y = it.first.first;
			ll z = it.first.second;
			
		//	cout << x << " " << dist[y][1] << " " << dist[z][n] << nl;
			ans = min(ans, (dist[y][1] + dist[z][n] + 1) * x);
			ans = min(ans, (dist[y][n] + dist[z][1] + 1) * x);
			ans = min(ans, (dist1[z] + 2) * x);
			ans = min(ans, (dist1[y] + 2) * x);
		}
		
		cout << ans << nl;
	}
}