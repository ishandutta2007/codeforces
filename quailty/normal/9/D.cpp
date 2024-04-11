#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
ll dp[45][45];
int main()
{
    int n,h;
    scanf("%d%d",&n,&h);
    dp[0][0]=1;
    for(int i=1;i<=n;i++)
        for(int j=0;j<n;j++)
            for(int k=0;k<=n;k++)
                for(int l=0;l<=n;l++)
                    dp[i][max(k,l)+1]+=dp[j][k]*dp[i-1-j][l];
    ll res=0;
    for(int i=h;i<=n;i++)
        res+=dp[n][i];
    printf("%I64d",res);
    return 0;
}