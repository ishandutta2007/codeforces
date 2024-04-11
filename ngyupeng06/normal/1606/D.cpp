#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
#define pb push_back

ll n, m, k, t, a, b, c;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--){
		cin >> n >> m;
		ll ar[n+1][m+1], arr[n+1][m+1];
		vector<pll> v;
		for (int i=0; i<n; i++){
			for (int j=0; j<m; j++) cin >> ar[i][j];
			v.pb(mp(-ar[i][0], i));
		}
		sort(v.begin(), v.end());
		for (int i=0; i<n; i++){
			int xx = v[i].second;
			for (int j=0; j<m; j++){
				arr[i][j] = ar[xx][j];
			}
		}
		ll tl[n+1][m+1], br[n+1][m+1], tr[n+1][m+1], bl[n+1][m+1];
		for (int i=0; i<n; i++){
			ll cur = 2e9;
			for (int j=0; j<m; j++){
				cur = min(cur, arr[i][j]);
				if (i) tl[i][j] = min(tl[i-1][j], cur);
				else tl[i][j] = cur;
		//		cout << tl[i][j] << " ";
			}
			cur = -2e9;
			for (int j=m-1; j>=0; j--){
				cur = max(cur, arr[i][j]);
				if (i) tr[i][j] = max(tr[i-1][j], cur);
				else tr[i][j] = cur;
		//		cout << tl[i][j] << " ";
			}
		//	cout << "\n";
		}
		for (int i=n-1; i>=0; i--){
			ll cur = 2e9;
			for (int j=m-1; j>=0; j--){
				cur = min(cur, arr[i][j]);
				if (i == n-1) br[i][j] = cur;
				else br[i][j] = min(br[i+1][j], cur);
			}
			cur = -2e9;
			for (int j=0; j<m; j++){
				cur = max(cur, arr[i][j]);
				if (i == n-1) bl[i][j] = cur;
				else bl[i][j] = max(bl[i+1][j], cur);
			}
		}
		ll thing = -1, thing2 = -1;
		for (int i=0; i<n-1; i++){
			ll x = n-i-1;
			for (int j=0; j<m-1; j++){
				if (tl[i][j] > bl[i+1][j] && br[i+1][j+1] > tr[i][j+1]) thing = i, thing2 = j+1;
			}
		}
		if (thing == -1){
			cout << "NO\n";
		}
		else {
			cout << "YES\n";
			char ans[n+1];
			for (int i=0; i<n; i++){
				if (i <= thing) ans[v[i].second] = 'R';
				else ans[v[i].second] = 'B'; 
			}
			for (int i=0; i<n; i++){
				cout << ans[i];
			}
			cout << " " << thing2 << "\n";
		}
	}
}