#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
///#define int long long
#define endl '\n'
typedef long long ll;
using namespace std;
ll a[300001];
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n,k;cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>a[i];
    if (n==1){
        cout<<a[1]+k;
        return 0;
    }
    sort(a+1,a+n+1);
    ll m=(n+1)/2;
    ll x=a[m];
    ll cnt=1;
    for (ll i=m+1;i<=n;i++){
        if (x+(k/(i-m))>=a[i]){
            k-=(a[i]-x)*(i-m)*1ll;
            x=a[i];
            cnt++;
        } else break;
    }
    cout<<x+(k/cnt);
    return 0;
}