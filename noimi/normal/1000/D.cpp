#include "bits/stdc++.h"
#define ll long long
#define rep2(i,a,b) for(int i=(a);i<=(b);++i)
#define rep(i,n) for(int i=0;i<n;i++)
#define pii pair<int,int>
#define ti3 tuple<int,int,int>
ll int MOD=998244353;
#define N 600000
 
using namespace std;
string alphabet("abcdefghijklmnopqrstuvwxyz");

main(){
    int n;
    cin>>n;
    int a[1100]={};
    rep2(i,1,n){cin>>a[i];}
    ll int dp[1100][1100]={};
    dp[0][0]=1;
    rep2(i,1,n){
        rep(j,n){
            if(j==a[i]&&j!=0) dp[i][j]+=dp[i-1][0];
            dp[i][j]+=dp[i-1][j]+dp[i-1][j+1];
            dp[i][j]%=MOD;
        }
    }
    cout<<dp[n][0]-1;
}