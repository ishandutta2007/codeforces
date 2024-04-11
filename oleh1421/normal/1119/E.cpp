#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll a[300001];
int main()
{
    int n;cin>>n;
    ll res=0ll;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        //res+=(a[i]/3ll)*1ll;
        //a[i]%=3ll;
    }
    res+=(a[1]/3ll)*1ll;
    a[1]%=3ll;
    ll cnt=a[1]*1ll;
    for (int i=2;i<=n;i++){
        //ll cur=min(cnt*1ll,a[i]/2ll)*1ll;
        ll x=max((a[i]-2ll*cnt)/3ll,0ll);
        ll cur=min(cnt*1ll+x*1ll,(a[i]-x)/2ll);
        res+=cur*1ll;
        cnt+=a[i]*1ll;
        cnt-=3ll*cur*1ll;
    }
    cout<<res*1ll;

    return 0;
}