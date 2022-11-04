#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=55;
int res[MAXN];
ll dp[MAXN][2][2];
ll cal(int n)
{
    memset(dp,0,sizeof(dp));
    dp[0][1][1]=1;
    for(int l=1,r=n;l<=r;l++,r--)
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
                for(int p=0;p<2;p++)
                    for(int q=0;q<2;q++)
                    {
                        if(l==r && p!=q)continue;
                        if(res[l]>=0 && res[l]!=p)continue;
                        if(res[r]>=0 && res[r]!=q)continue;
                        if((i && p>q) || (j && p>!q))continue;
                        dp[l][i && p==q][j && p==!q]+=dp[l-1][i][j];
                    }
    ll res=0;
    for(int j=0;j<2;j++)
        for(int k=0;k<2;k++)
            res+=dp[(n+1)/2][j][k];
    return res;
}
int main()
{
    ll n,k;
    scanf("%I64d%I64d",&n,&k);
    memset(res,-1,sizeof(res));
    k++;
    for(int i=1;i<=n;i++)
    {
        res[i]=0;
        ll t=cal(n);
        if(k>t)res[i]=1,k-=t;
    }
    if(res[1])printf("-1\n");
    else for(int i=1;i<=n;i++)
        printf("%d",res[i]);
    return 0;
}