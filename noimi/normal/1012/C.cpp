#include "bits/stdc++.h"
#define ll long long
#define rep2(i,a,b) for(int i=a;i<=b;++i)
#define rep(i,n) for(int i=0;i<n;i++)
#define pii pair<int,int>
#define tii tuple<int,int,int>
#define pq priority_queue<int>
#define pqg priority_queue<int,vector<int>,greater<int>>
#define pb push_back
#define edge(v,a,b) v[a].pb(b);v[b].pb(a);
ll MOD=1e9+7;
#define INF 2*1e9
#define N 6000
using namespace std;
string alphabet("abcdefghijklmnopqrstuvwxyz");
main(){
    int dp[N][3];
    rep(i,N){
        dp[i][0]=dp[i][1]=dp[i][2]=INF;
    }
    int n;cin>>n;
    int a[N];
    a[n]=-INF;
    rep(i,n){
        cin>>a[i];
    }
    dp[0][0]=0;
    rep2(iii,1,n){
    for(int i=(n+1)/2;i>0;i--){
        dp[i][0]=min(dp[i][0],dp[i][2]);
        dp[i][2]=dp[i][1];
        if(iii>2){
            int s=min(a[iii-2],a[iii-3]-1);
            s=max(s-a[iii-1]+1,0);
            s+=max(a[iii]-a[iii-1]+1,0);
            int t=max(a[iii]-a[iii-1]+1,0)+max(a[iii-2]-a[iii-1]+1,0);
            dp[i][1]=min(dp[i-1][2]+s,dp[i-1][0]+t);
        }
        else if(iii==2&&i==1){
            dp[1][1]=max(0,a[0]-a[1]+1)+max(0,a[2]-a[1]+1);
        }
        else if(iii==1&&i==1){
            dp[1][1]=max(0,a[1]-a[0]+1);
        }
    }
    }
    int ans[N];
    ans[(n+1)/2]=min({dp[(n+1)/2][0],dp[(n+1)/2][1],dp[(n+1)/2][2]});
    for(int i=(n+1)/2-1;i>0;i--){
        ans[i]=min(ans[i+1],min({dp[i][0],dp[i][1],dp[i][2]}));
    }
    rep2(i,1,(n+1)/2){
        cout<<ans[i]<<" ";
    }
    return 0;
}