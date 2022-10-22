#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
#define pb push_back

ll n, m, k, t, a, b, c;
char arr1[405][405];
ll arr[405][405], sum[405][405];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	for (int tc=1;tc<=t;tc++){
		cin >> n >> m;
		for (int i=1; i<=n; i++){
			for (int j=1; j<=m; j++){
				arr[i][j] = sum[i][j] = 0;
				cin >> arr1[i][j];
				arr[i][j] = arr1[i][j] - '0';
				sum[i][j] = sum[i][j-1] + arr[i][j];
			}
		}
		ll ans = 2e9;
		ll curm;
		ll sum1 = 0;
		for (int j=1; j<=m; j++){
			for (int k=j+3; k<=m; k++){
				sum1 = 0;
				vector<ll> v;
				curm = -2e9;
				for (int i=1; i<=n; i++){
					ll s = sum[i][k-1]-sum[i][j];
					ll x = sum1 + (k-j-1) - s;
					if (i>=5){
						curm = max(curm, v[i-5]);
						ans = min(ans, x - curm);
					}
					v.pb(sum1 - (k-j-1) + s + 2-arr[i][j]-arr[i][k] + s);
			//		cout << sum1 - (k-j-1) + s + 2-arr[i][j]-arr[i][k] + s << " " << sum1 << "\n";
					sum1 += s + 2-arr[i][j]-arr[i][k];
					
				}
			}
		}
		
		cout << ans << "\n";
	}
}