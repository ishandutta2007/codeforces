#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
#define mod 1000000007
#define reset(s,val) memset(s,val,sizeof(s))
#define eps 1e-8
#define pi acos(-1)
#define sqr(x) (x)*(x)
#define two(x) (1<<(x))

int n,lis[111],dp[3][111];

int main( ){
    // freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n;
    For(i,0,n) cin>>lis[i];
    if(lis[0]==1||lis[0]==3) dp[1][0]=1;
    if(lis[0]==2||lis[0]==3) dp[2][0]=1;
    For(i,1,n) {
        if(lis[i]==1||lis[i]==3) {
            dp[1][i] = 1+max(dp[0][i-1], dp[2][i-1]);
        }
        if(lis[i]==2||lis[i]==3) {
            dp[2][i] = 1+max(dp[0][i-1], dp[1][i-1]);
        }
        dp[0][i] = max(max(dp[0][i-1], dp[1][i-1]), dp[2][i-1]);
        // For(j,0,3) cout<<dp[j][i]<<' ';cout<<endl;
    }
    cout<<n-max(max(dp[0][n-1], dp[1][n-1]), dp[2][n-1]);
}