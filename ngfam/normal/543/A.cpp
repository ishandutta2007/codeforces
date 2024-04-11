#include<bits/stdc++.h>
using namespace std;
const int maxN=5e2+1;
int dp[maxN][maxN],A[maxN],n,m,b,mod;
void enter(){
    cin>>n>>m>>b>>mod;
    for(int i=1;i<=n;i++)cin>>A[i];
}
void init(){
    for(int i=1;i<=m;i++)
       for(int j=1;j<=b;j++)
           dp[i][j]=0;
    dp[0][0]=1;
}
void solve(){
    for(int i=1;i<=n;i++)
       for(int j=1;j<=m;j++)
          for(int k=0;k<=b-A[i];k++){
                dp[j][k+A[i]]+=dp[j-1][k];
                if(dp[j][k+A[i]]>=mod)dp[j][k+A[i]]-=mod;
             }
    int res=0;
    for(int i=0;i<=b;i++){
        res+=dp[m][i];
        res%=mod;
    }
    cout<<res;
}
int main(){
    enter();
    init();
    solve();
}