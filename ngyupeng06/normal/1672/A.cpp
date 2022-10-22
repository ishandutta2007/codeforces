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

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--){
		cin >> n;
		ll sum = 0;
		for (int i=0; i<n; i++){
			ll a;
			cin >> a;
			sum += a-1;
		}
		if (sum  %2 == 0) cout << "maomao90\n";
		else cout << "errorgorn\n"; 
	}
}