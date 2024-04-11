#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll p[1000001];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n,m,k;cin>>n>>m>>k;
    for (int i=1;i<=m;i++) cin>>p[i];
    vector<ll>v;
    for (int i=1;i<=m;i++) v.push_back(p[i]);
    ll pos=0;
    ll del=0;
    ll res=0;
    while (pos<m){
        ll page=(v[pos]-del-1ll)/k+1ll;
        ll ind=upper_bound(v.begin(),v.end(),page*k+del)-v.begin();
        res++;
        pos=ind;
        del=ind;
    }
    cout<<res;
    return 0;
}
//2 6 -2 -6  2