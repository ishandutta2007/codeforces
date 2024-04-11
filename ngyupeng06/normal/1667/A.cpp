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
ll arr[5005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i=0; i<n; i++){
		cin >> arr[i];
	} 
	ll ans = 1e18;
	
	for (int i=0; i<n; i++){
		ll cur = 0, cur1 = 0;
		ll ans1 = 0;
		for (int j=i+1; j<n; j++){
			cur = cur - cur%arr[j] + arr[j];
			ans1 += cur/arr[j];
		}
		cur = 0;
		for (int j=i-1; j>=0; j--){
			cur = cur - cur%arr[j] + arr[j];
			ans1 += cur/arr[j];
		}
		ans = min(ans, ans1);
	}
	
	cout << ans;
}