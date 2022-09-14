#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=200010;
ll a,b,q;
ll get(ll l,ll r){
    ll res=0ll;
    while (l%b && l<=r){
        res+=(((l%a)%b)==((l%b)%a));
        l++;
    }
    while (r%b!=b-1 && l<=r){
        res+=(((r%a)%b)==((r%b)%a));
        r--;
    }
    if (l<=r){
        ll c=a/__gcd(a,b);
        l/=b;
        r/=b;
        res+=(r/c-(l-1ll)/c)*b;
    }
    return res;
}
void solve(){
    cin>>a>>b>>q;
    if (a>b) swap(a,b);
    for (int i=1;i<=q;i++){
        ll l,r;cin>>l>>r;
        cout<<r-l+1ll-get(l,r)<<" ";
    }
    cout<<endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}