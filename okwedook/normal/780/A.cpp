#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;

int main() {    
    ll n;
    cin >> n;
    n *= 2;
    set<ll> myset;
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
    	ll temp;
    	cin >> temp;
    	if (myset.count(temp)) 
    		myset.erase(temp);
    	else
    		myset.insert(temp);
    	ans = max(ans, (ll)myset.size());
    }
    cout << ans;
    return 0;
}