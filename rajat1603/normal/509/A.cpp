#include<bits/stdc++.h>
using namespace std;
#define getchar_unlocked() getchar()
inline int scan(){
    char c = getchar_unlocked();
    int x = 0;
    while(c<'0'||c>'9'){
        c=getchar_unlocked();
    }
    while(c>='0'&&c<='9'){
        x=(x<<1)+(x<<3)+c-'0';
        c=getchar_unlocked();
    }
    return x;
}
#define pb push_back
#define mp make_pair
int main(){
    int n=scan();
    int dp[11][11];
    for(int i=1;i<=n;i++)dp[i][1]=1,dp[1][i]=1;
    for(int i=2;i<=n;i++){
        for(int j=2;j<=n;j++){
            dp[i][j]=dp[i-1][j]+dp[i][j-1];
        }
    }
    cout<<dp[n][n];
}