//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
//#define int ll
#define endl '\n'
const int N=1000100;
const ll mod=998244353;
const ll inf=2000000000000000000;
ll a[N];
void solve(){
    int n;cin>>n;
    ll sum=0ll;
    for (int i=1;i<=n;i++) cin>>a[i],sum+=a[i];
    sort(a+1,a+n+1);
    int m;cin>>m;
    for (int it=1;it<=m;it++){
        ll x,y;cin>>x>>y;
        int ind=upper_bound(a+1,a+n+1,x)-a;
        ll A=inf;
        if (ind<=n) A=max(0ll,y-(sum-a[ind]));
        ll B=inf;
        if (ind>=2) B=max(0ll,y-(sum-a[ind-1]))+x-a[ind-1];
        cout<<min(A,B)<<endl;
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }

    return 0;
}
//1 3 3 4
//0 1 2 3