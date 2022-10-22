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
	cin >> n;
	ll lo = 1, hi = 4004000;
	ll ans = 0, a, ans1;
	while (lo <= hi){
		ll mid = (lo+hi)/2;
		cout << "? " << mid << endl;
		cin >> a;
		if (a==1){
			ans = mid;
			hi = mid-1;
		}
		else {
			lo = mid + 1;
		}
	}
	ans1 = ans;
	for (int i=2; i<=n; i++){
		ll c = (ans - i + 1)/i;
		if ((ans - i + 1)%i != 0) c++;
		cout << "? " << c << endl;
		cin >> a;
		if (a!=0) ans1 = min(ans1, a*c);
	}
	cout << "! " << ans1;
	
}