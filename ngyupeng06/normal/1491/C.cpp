#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
#define pb push_back

ll n, m, arr[5005], ans, moves, t;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >>  t;
	while(t--){
		cin >> n;
		ans = moves = 0;
		for (int i=0; i<n; i++){
			cin >> arr[i];
			ll cnt = 0;
			if (i==0){
				ans = moves = arr[i]-1;
				continue;
			}
			for (int j=0; j<i-1; j++){
				if (arr[j]+j >= i) cnt++;
			}
			ll x = moves - arr[i-1] + 1;
			if (x + cnt >= arr[i]-1){
				moves = x + cnt;
			}
			else {
				moves = arr[i] - 1;
				ans += arr[i] - 1 - x - cnt;
			}
		}
		cout << ans << "\n";
	}
}