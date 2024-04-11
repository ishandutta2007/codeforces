/*
   .
#???????
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fi first
#define se second
#define mp make_pair

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll l,r;
    cin >> l >> r;
    for(ll j = l;j<=r;j++){
        for(ll x = j+1;x<=r;x++){
            for(ll v = x+1;v<=r;v++){
                if(__gcd(j,x) == 1 && __gcd(x,v) == 1 && __gcd(j,v) != 1){
                    cout << j << " " << x << " " << v;
                    exit(0);
                }
            }
        }
    }
    cout << -1;
    return 0;
}