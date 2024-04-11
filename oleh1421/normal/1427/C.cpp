#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=100010;
int x[N],y[N],t[N],dp[N],pref[N];
void solve(){
    int r,n;cin>>r>>n;
    for (int i=0;i<=n;i++) dp[i]=-1000000001;
    for (int i=1;i<=n;i++) cin>>t[i]>>x[i]>>y[i];
    dp[0]=0;
    pref[0]=0;
    t[0]=0;
    x[0]=1;
    y[0]=1;
    for (int i=1;i<=n;i++){
        if (i>=r*2) dp[i]=pref[i-r*2]+1;
        for (int j=i-1;j>=0 && j>=i-r*2;j--){
            if (t[j]+abs(x[i]-x[j])+abs(y[i]-y[j])<=t[i]){
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
        pref[i]=max(pref[i-1],dp[i]);
    }
    cout<<pref[n]<<endl;

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}