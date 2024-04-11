#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
#define pb push_back

ll n, m, t, arr[555][555];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--){
		cin >> n;
		ll sum = 0, cmax = 2e9;
		for (int i=1; i<=2*n; i++){
			for (int j=1; j<=2*n; j++){
				cin >> arr[i][j];
				if (i == 1){
					if (j == n+1 || j == 2*n) cmax = min(cmax,arr[i][j]);
				}
				if (i == n){
					if (j == n+1 || j == 2*n) cmax= min(cmax, arr[i][j]);
				}
				if (i == n+1){
					if (j==1 || j==n) cmax = min(cmax, arr[i][j]);
				}
				if (i==2*n){
					if (j==1 || j==n) cmax = min(cmax, arr[i][j]);
				}
				if (i > n && j > n) sum += arr[i][j];
			}
		}
		cout << sum + cmax << "\n";
	}
}