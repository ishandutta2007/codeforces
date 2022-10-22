#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
#define pb push_back

ll n, e, k, t, a, b, c;
bool vis[1000005];
ll arr[2000005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	for (ll i=2; i<1000005; i++){
		if (vis[i]) continue;
		for (ll j=i*i; j<1000005; j+=i){
			vis[j] = true;
		}
	}

	cin >> t;
	while (t--){
		cin >> n >> e;	
		for (int i=0; i<n; i++){
			cin >> arr[i];
		}
		for (int i=n; i<n+e; i++){
			arr[i] = 4;
		}
		ll ans = 0;
		for (int i=0; i<e; i++){
			ll cur1 = 0, cur2 = 0;
			bool gd = false;
			for (int j=i; j<n+e; j+=e){
				if (arr[j] == 1 && !gd) cur1++;
				else if (arr[j] == 1){
					cur2++;
				}
				else if (vis[arr[j]] && gd){
					ans += (cur1+1) * (cur2+1) - 1;
					cur1 = cur2 = 0;
					gd = false;
				}
				else if (vis[arr[j]]){
					cur1 = cur2 = 0;
					gd = false;
				}
				else if (gd){
					ans += (cur1+1) * (cur2+1) - 1;
					cur1 = cur2;
					cur2 = 0;
				}
				else {
					gd = true;
				}
			}
			
		}
		cout << ans << "\n";
	}
}