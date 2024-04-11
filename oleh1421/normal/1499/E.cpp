//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define endl '\n'
using namespace std;
const int N=1010;
const ll mod=998244353;
ll dp[N][N][2];
int lastX[N];
int lastY[N];
int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string x,y;cin>>x>>y;
    int n=x.size(),m=y.size();
    x="."+x;
    y="."+y;

    for (int i=1;i<=n;i++){
        lastX[i]=lastX[i-1];
        if (x[i]==x[i-1]) lastX[i]=i-1;
        dp[i][0][0]=i-lastX[i];
    }
    for (int i=1;i<=m;i++){
        lastY[i]=lastY[i-1];
        if (y[i]==y[i-1]) lastY[i]=i-1;
        dp[0][i][1]=i-lastY[i];
    }
    ll res=0ll;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            dp[i][j][0]=1ll;
            if (i>1 && x[i-1]!=x[i]) dp[i][j][0]+=dp[i-1][j][0];
            if (x[i]!=y[j]) dp[i][j][0]+=dp[i-1][j][1];
            dp[i][j][0]%=mod;
            dp[i][j][1]=1ll;
            if (j>1 && y[j-1]!=y[j]) dp[i][j][1]+=dp[i][j-1][1];
            if (x[i]!=y[j]) dp[i][j][1]+=dp[i][j-1][0];
            dp[i][j][1]%=mod;
            res+=dp[i][j][0]+dp[i][j][1]-(i-lastX[i])-(j-lastY[j])+mod;
            res%=mod;
//            cout<<i<<" "<<j<<" "<<dp[i][j][0]<<" "<<dp[i][j][1]<<endl;
        }
    }
    cout<<res<<endl;
    return 0;
}
/**
a
b 2 4 = 8

aa 1 2 =2
b

a  1 2 =2
bb

aa
bb 2 1 =2
**/