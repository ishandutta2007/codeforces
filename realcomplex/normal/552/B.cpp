#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fi first
#define se second

int main(){

    ll n;
    cin >> n;
    ll ans = 0;
    ll l = 1;
    ll t = 10;
    ll c = 1;
    while(t<=n){
        ans += (min(n,t)-l)*c;
        c++;
        l*=10;
        t*=10;
    }
    cout << ans+((n-l+1)*c);
    return 0;
}