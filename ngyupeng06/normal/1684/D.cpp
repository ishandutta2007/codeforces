#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define nl "\n"
#define all(v) v.begin(),v.end()

ll n, m, t;
ll arr[200005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while(t--){
		cin >> n >> m;
		vector<int> v;
		ll sum = 0;
		for (int i=0; i<n; i++){
			cin >> arr[i];
			sum += arr[i];
			v.pb(arr[i] - (n-i-1));
		}
		sort(all(v));
		for (int i=n-1; i>n-1-m; i--){
			sum -= v[i];
			sum -= (n-1-i);
		}
		cout << sum << nl;
	}
}