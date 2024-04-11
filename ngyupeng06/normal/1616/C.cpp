#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
#define pb push_back

ll n, m, t, arr[105];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--){
		cin >> n;
		for (int i=0; i<n; i++){
			cin >> arr[i];
		}
		ll ans = n-1;
		for (int i=0; i<n; i++){
			for (int j=i+1; j<n; j++){
				ll di = arr[j]-arr[i];
				ll cnt = 0;
				for (int k=0; k<n; k++){
					if (arr[k] * (j-i) != arr[i]*(j-i) + (k-i)*di) cnt++;
				}
				ans = min(ans, cnt);
			}
		}
		cout << ans << '\n';
	}
}