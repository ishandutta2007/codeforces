#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
#define pb push_back

ll n, m, k, t, a, b, c, arr[200005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--){
		cin >> n;
		for (int i=0; i<n; i++){
			cin >> arr[i];
		}
		bool gd = true;
		ll x, y;
		for (int i=0; i<n/2; i++){
			if (arr[i] != arr[n-1-i]){
				x = arr[i], y = arr[n-1-i];
				vector<int> v, v1;
				for (int i=0; i<n; i++){
					if (arr[i] != x) v.pb(arr[i]);
					if (arr[i] != y) v1.pb(arr[i]);
				}
				int sz1 = v.size(), sz2 = v1.size();
				bool gd1 = true, gd2 = true;
				for (int i=0; i<v.size(); i++){
					if (v[i] != v[sz1-i-1]) gd1 = false;
				}
				for (int i=0; i<sz2; i++){
					if (v1[i] != v1[sz2-i-1]) gd2 = false;
				}
				if (!gd1 && !gd2) gd = false;
				break;
			}
		}
		if (gd) cout << "YES\n";
		else cout << "NO\n";
	}
}