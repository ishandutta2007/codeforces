#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll a[200001];
map<ll,ll>used;
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    bool ok=false;
    for (int i=1;i<=n+n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+n+1);
    ll res=(a[n]-a[1])*(a[n+n]-a[n+1]);
    for (int i=2;i<=n;i++){
        res=min(res,(a[n+n]-a[1])*(a[i+n-1]-a[i])*1ll);
    }
    cout<<res;
    return 0;
}
//2 6 -2 -6  2