#include<bits/stdc++.h>
using namespace std;
#define far(i,t,n) for(int i=t;i<n;++i)
#define pk(a) push_back(a)
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
 
ll dp[40][40];
 
void getDp(int n)
{
    for(int i=0;i<=n;++i)
        dp[0][i]=1;
    for(int j=1;j<=n;++j)
    {
        for(int i=1;i<=n;++i)
            for(int k=0;k<i;++k)
            {
                dp[i][j]+=dp[k][j-1]*dp[i-k-1][j-1];
                //cout<<i<<" "<<j<<" "<<k<<" "<<dp[i][j]<<endl;
            }
    }
}
 
int main()
{
    int n,h;
    cin>>n>>h;
    getDp(n);
    ll ans=dp[n][n]-dp[n][h-1];
    cout<<ans<<"\n";
}