#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
#define pb push_back

ll n, m, k, t, a, b, c, arr[200005][2];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--){
	
		cin >> n;
		for (int i=0; i<n; i++){
			cin >> arr[i][1] >> arr[i][0];
		}	
		ll lo = 1, hi = n, ans = 1;
		while (lo <= hi){
			ll mid = (lo + hi)/2;
			ll cur = 0;
			for (int i=0; i<n; i++){
				if (cur >= mid) break;
				if (arr[i][0] >= cur && arr[i][1] >= mid - cur - 1){
					cur++;
				}
			}
			if (cur >= mid){
				ans = mid;
				lo = mid+1;
			}
			else {
				hi = mid-1;
			}
		}
		cout << ans << "\n"; 
	}
}