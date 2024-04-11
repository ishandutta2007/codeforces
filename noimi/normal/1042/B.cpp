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
#define N 600010
#define MAX_V 900010
using namespace std;
main(){
    int n;cin>>n;
    pii a[N];
    rep(i,n){
        cin>>a[i].first;
        string s;
        cin>>s;
        int t=0;
        rep(j,s.size()){
            t+=pow(2,s[j]-'A');
        }
        a[i].second=t;
    }
    int dp[N][8]={};
    rep(i,N)rep(j,8)dp[i][j]=INF;
    dp[0][0]=0;
    rep(i,n){
        rep(j,8){
            dp[i+1][j|a[i].second]=min(dp[i+1][j|a[i].second],dp[i][j]+a[i].first);
            dp[i+1][j]=min(dp[i][j],dp[i+1][j]);
        }
    }
    cout<<(dp[n][7]==INF?-1:dp[n][7]);

}