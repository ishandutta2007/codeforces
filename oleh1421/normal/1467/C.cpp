//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=305010;
const ll mod=1000000007;
ll a[3][N];
ll n[3];
ll mn[3];
ll sum[3];
void solve(){
    cin>>n[0]>>n[1]>>n[2];
    for (int i=0;i<3;i++){
        mn[i]=1000000001;
        for (int j=0;j<n[i];j++) cin>>a[i][j],sum[i]+=a[i][j],mn[i]=min(mn[i],a[i][j]);
    }
    cout<<sum[0]+sum[1]+sum[2]-2*min({sum[0],sum[1],sum[2],mn[0]+mn[1],mn[0]+mn[2],mn[1]+mn[2]})<<endl;
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