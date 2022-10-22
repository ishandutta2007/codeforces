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

ll n, m, t, arr[200005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while(t--){
		cin >> n;
		ll sum = 0;
		for (int i=0; i<n; i++){
			cin >> arr[i];
			sum += arr[i];
		}
		ll cnt = 0;
		bool gd = true;
		bool gd1 = false;
		for (int i=n-1; i>=0; i--){
			if (arr[i] != 0) gd1 = true;
			if (arr[i] > cnt) gd = false;
			cnt = cnt - arr[i];
			if (gd1 == true && i != 0 && cnt == 0) gd = false;
		}
		if (gd && sum == 0) cout << "Yes\n";
		else cout << "No\n";
	}
}