#include<bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=5010;
ll a[N],b[N];
ll dp[N][N];
void solve(){
    int n;cin>>n;
    ll res=0ll;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++) cin>>b[i];
    for (int len=2;len<=n;len++){
        for (int l=1,r=len;r<=n;l++,r++){
            dp[l][r]=dp[l+1][r-1]+a[r]*b[l]+a[l]*b[r]-a[l]*b[l]-a[r]*b[r];
            res=max(res,dp[l][r]);
        }
    }
    for (int i=1;i<=n;i++) res+=a[i]*b[i];
    cout<<res<<endl;

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}