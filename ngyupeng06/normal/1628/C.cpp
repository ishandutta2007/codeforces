#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
#define pb push_back

ll n, m, t, arr[1005][1005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--){
		cin >> n;
		for (int i=0; i<n; i++){
			for (int j=0; j<n; j++){
				cin >> arr[i][j];
			}
		}
		ll sum = 0;
		for (int i=0; i<=2*n-2; i+=4){
			int a, b;
			if (i > n-1){
				a = n-1, b = i-n+1;
			}
			else {
				a = i, b = 0;
			}
			while (a >= 0 && b <= n-1){
				sum ^= arr[a][b];
				sum ^= arr[a][n-1-b];
				a -= 2;
				b += 2;
			}
		}
		cout << sum << "\n";
	}
}