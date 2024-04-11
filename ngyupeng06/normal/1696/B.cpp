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
		ll a = 0;
		bool gd=true;
		ll cnt = 0;
		for (int i=0;i <n; i++){
			cin >> arr[i];
			if (arr[i] != 0) gd = false;
			if (arr[i] != 0 && a == 0) cnt++;
			a = arr[i];
		}
		if (cnt == 1) cout << 1;
		else if (cnt == 0) cout << 0;
		else cout << 2;
		cout << nl;
	}
}