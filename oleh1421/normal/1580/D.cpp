#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
//#define int ll
//#define endl '\n'
using namespace std;
mt19937_64 rnd(time(NULL));
const int N=5010;
ll a[N];
int n,m;
vector<ll>rec(int l,int r){
    vector<ll>dp(r-l+2,0);
    if (l>r) return dp;
    int mn=l;
    for (int i=l+1;i<=r;i++){
        if (a[i]<a[mn]) mn=i;
    }
    auto A=rec(l,mn-1);
    auto B=rec(mn+1,r);
    vector<ll>cur(2,0);
    cur[1]=a[mn]*(m-1ll);
    for (int i=0;i<A.size();i++){
        for (int j=0;j<B.size();j++){
            for (int t=0;t<cur.size();t++){
                dp[i+j+t]=max(dp[i+j+t],A[i]+B[j]+cur[t]-a[mn]*(i*j+t*i+t*j)*2ll);
            }
        }
    }
    return dp;
}
void solve(){
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i];
    auto ans=rec(1,n);
    cout<<ans[m]<<endl;


}
int32_t  main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}
/**
1
4
1 2 5 2
BRBR
**/