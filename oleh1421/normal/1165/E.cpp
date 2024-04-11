#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll a[1000001];
ll b[1000001];
int main()
{
    ll n;cin>>n;
    vector<pair<ll,ll> >x;
    vector<ll>v;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        v.push_back((1ll*i*(n-i+1ll)*a[i]*1ll));
    }
    for (int i=1;i<=n;i++) cin>>b[i];
    sort(b+1,b+n+1);
    reverse(b+1,b+n+1);
    sort(v.begin(),v.end());
    ll res=0ll;
    for (int i=0;i<n;i++){
        v[i]%=998244353ll;
        res+=v[i]*b[i+1]*1ll;
        res%=998244353ll;
    }
    cout<<res*1ll;
    return 0;
}