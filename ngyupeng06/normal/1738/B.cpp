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

ll n, m, q, k, t, a, b, c;
ll arr[100005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> n >> m;
		bool gd = true;
		for (int i = 0; i<m; i++) {
			cin >> arr[i];
			if (i >= 2 && arr[i] - arr[i-1] < arr[i-1] - arr[i-2]) gd = false;
		}
		if (n == 1 || m == 1){
			cout << "Yes" << nl;
			continue;
		}
		if (!gd) {
			cout << "No" << nl;
			continue;
		}
		ll x = arr[1] - arr[0];
		if (x * (n-m+1) < arr[0]){
			cout << "No" << nl;
		}
		else cout << "Yes" << nl;
	}
	

}