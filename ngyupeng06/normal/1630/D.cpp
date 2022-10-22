#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
#define pb push_back

ll n, m, t, cnt[1000005], cmin[1000005], arr[1000005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--){
		cin >> n >> m;
		ll sum = 0;
		for (int i=0; i<=n; i++){
			cnt[i] = 0;
			cmin[i] = 2e9;
		}
		for (int i=0; i<n; i++){
			cin >> arr[i];
			sum += abs(arr[i]);
		}
		ll x = 0, a;
		for (int i=0; i<m; i++){
			cin >> a;
			x = __gcd(a,x);
		}
		for (int i=0; i<n; i++){
			ll y = i%x;
			if (arr[i] < 0) cnt[y]++;
			cmin[y] = min(cmin[y], abs(arr[i]));
		}
		ll suma = 0, sumb = 0;
		for (int i=0; i<x; i++){
			if (cnt[i] % 2){
				suma += 2*cmin[i];
			}
			else {
				sumb += 2*cmin[i];
			}
		}
		cout << sum - min(suma, sumb) << "\n";
	}
}