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
    ll n;
    cin >> n;
    ll sum[n+1];
    sum[0] = 0;
    for(ll j = 1;j<=n;j++){
        cin >> sum[j];
        sum[j]+=sum[j-1];
    }
    if(sum[n]%3!=0){
        cout << "0";
        exit(0);
    }
    ll h = sum[n]/3;
    map<ll,ll>k;
    ll ans = 0;
    for(ll j = 1;j<=n;j++){
        if(sum[j] == h*2 && j!=n){
            ans += k[h];
        }
        k[sum[j]]++;
    }
    cout << ans;
    return 0;
}