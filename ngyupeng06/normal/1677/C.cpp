#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
#define pb push_back
#define nl "\n"
#define all(v) v.begin(),v.end()

ll n, m, t;
ll arr[100005], brr[100005], a[100005], b[100005];
bool vis[100005];


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--){
		cin >> n;
		for (int i=0; i<=n; i++){
			vis[i] = false;
		}
		for (int i=0; i<n; i++){
			cin >> arr[i];
			a[arr[i]] = i;
		}
		for (int i=0; i<n; i++){
			cin >> brr[i];
			b[brr[i]] = i;
		}
		ll sum = 0;
		for (int i=0; i<n; i++){
			if (vis[i]) continue;
			vis[i] = true;
			ll cnt = 1;
			ll x = i;
			while (true){
				x = a[brr[x]];
				if (vis[x]) break;
				vis[x] = true;
				cnt++;
			}
			sum += cnt;
			if (cnt%2) sum--;
	//		cout << cnt << " ";
		}
	//	cout << sum << nl;
		ll ans=0;
		for (int i=0; i<sum/2; i++){
			ans += 2*(n-i-(i+1));
		}
		cout << ans << nl;
	}
}