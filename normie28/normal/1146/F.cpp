#include <bits/stdc++.h>
using namespace std;
vector<long long> gt[200001];
long long dp[200001][3],n,m,i,j,k,t,t1,u,v,a,b;
const long long MOD=998244353;
void calc(long long x)
{
    if (!gt[x].size())
    {
        dp[x][2]=1;
    }
    else
    {
        for (long long g : gt[x]) calc(g);
        long long a,b,c0=0,c1=0,c2=0;
        a=1;
        for (long long g : gt[x])
        {
            b=(dp[g][0]+dp[g][2]);
            a*=b;
            a%=MOD;
        }
        dp[x][0]=a;
        long long d0=1,d1=0,d2,d3;
        for (long long g : gt[x])
        {
            d2=d0*(dp[g][0]+dp[g][2]);
            d3=d1*(dp[g][0]+dp[g][2]);
            d3+=d0*(dp[g][2]+dp[g][1]);
            d0=(d2%MOD);
            d1=(d3%MOD);
        }
        c1=d1;
        c2=1;
        for (long long g: gt[x]) c2=(c2*(dp[g][0]+dp[g][1]+(dp[g][2])*2))%MOD;
        c0=1;
        for (long long g: gt[x]) c0=(c0*(dp[g][0]+dp[g][2]))%MOD;
        dp[x][1]=c1;
        dp[x][2]=(c2-c0-c1+2*MOD)%MOD;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (i=2;i<=n;i++) {cin>>u; gt[u].push_back(i);}
    calc(1);
    cout<<(dp[1][0]+dp[1][2])%MOD<<endl;
}