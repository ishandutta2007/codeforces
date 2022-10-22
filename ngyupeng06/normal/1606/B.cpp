#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
#define pb push_back

ll n, m, k, t, a, b, c;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while(t--){
		cin >> a >> b;
		ll ans = 0, cur = 1;
		while (cur<=b && cur < a){
			ans++;
			cur*=2;
		}
		if (cur < a){
			ans += (a-cur)/b;
			if (a%b != cur%b) ans++;
		}
		cout<<ans << "\n";
	}
}