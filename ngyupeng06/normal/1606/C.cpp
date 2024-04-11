#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
#define pb push_back

ll n, m, k, t, a, b, c, arr[15], brr[15], p[15];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--){
		cin >> n >> k;
		for (int i=0; i<n; i++){
			cin >> arr[i];
		}
		ll cnt = 1;
		for (int i=0; i<n-1; i++){
			ll cur = 1;
			p[i] = cnt;
			for (int j=arr[i]; j<arr[i+1]; j++){
				cur *= 10;
				cnt*=10;
			}
			brr[i] = cur;
		//	cout << i << " " << p[i] << "\n";
		}
		p[n-1] = cnt;
		brr[n-1] = 1e10;
		ll ans = 0;
		for (int i=0; i<n; i++){
			if (k >= brr[i]-1){
				k -= brr[i]-1;
				ans += p[i] * (brr[i] - 1);
			}
			else {
				ans += (k+1) * p[i];
				k = -1;		
			}
	//			cout << i << "TEST " << k << "\n";
		}
		cout << ans << "\n";
	}
}