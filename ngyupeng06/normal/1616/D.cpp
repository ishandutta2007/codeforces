#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
#define pb push_back

ll n, m, t, x, arr[50005], sum[50005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--){
		cin >> n;
		for (int i=1; i<=n; i++){
			cin >> arr[i];
			sum[i] = 0;
		}
		cin >> x;
		ll cmax = -2e18;
		ll cur = 0;
		ll st = 1;
		for (int i=1; i<=n; i++){
			arr[i] -= x;
			sum[i] = sum[i-1] + arr[i];
			if (sum[i] - cmax < 0){
				st = i+1;
				cmax = -2e18;
			}
			else {
				cur++;
				cmax = max(cmax, sum[i-1]);
			}
		}
		cout << cur << '\n';
	}
}