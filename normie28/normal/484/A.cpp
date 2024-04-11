#include <bits/stdc++.h>
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll ; 
typedef long double ld ;
typedef pair<ll , ll> pll ;
 
const ll N = 2e5 + 30 , Mod = 1e9 + 7 ;
const ll SQ = 330 ;
 
 
int main () {
    ios::sync_with_stdio(0), cin.tie(0) ;
   	ll n ;
   	cin>>n ; 
   	while (n --) {
   		ll l,r ;
		cin>>l>>r ;
		for (int i  = 0 ; i < 61 ; i ++) 
			if (!(l & (1ll << i))) 
				if ((l | (1ll << i)) <= r)
					l |= (1ll << i) ;
		cout << l << endl;
	}
    return (0) ;
}