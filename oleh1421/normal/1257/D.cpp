#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
//#define int long long
int a[300001];
int p[300001];
int lg[300001];
int dp[300001][20];
int get(int l,int r){
    return max(dp[l][lg[r-l+1]],dp[r-(1<<lg[r-l+1])+1][lg[r-l+1]]);
}
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i],p[i]=0;
    int m;cin>>m;
    for (int i=1;i<=m;i++) {
        int x,y;cin>>x>>y;
        p[y]=max(p[y],x);
    }
    for (int i=n-1;i>=1;i--) p[i]=max(p[i],p[i+1]);
    for (int i=1;i<=n;i++) dp[i][0]=a[i];
    for (int t=1;(1<<t)<=n;t++){
        for (int i=1;i+(1<<t)-1<=n;i++){
            dp[i][t]=max(dp[i][t-1],dp[i+(1<<(t-1))][t-1]);
        }
    }
   // cout<<get(1,n)<<endl;
    int cur=1;
    int cnt=0;
    while (cur<=n){
        int jump=0;
        for (int i=1;cur+i-1<=n;i++){
            if (get(cur,cur+i-1)>p[i]) break;
            jump++;
        }
        if (jump==0){
            cout<<-1<<endl;
            return;
        }
        cur+=jump;
        cnt++;
    }
    cout<<cnt<<endl;
 
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    lg[1]=0;
    for (int i=2;i<=200000;i++) lg[i]=lg[i/2]+1;
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}