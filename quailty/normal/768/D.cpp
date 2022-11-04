#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef double db;
const db eps=1e-7;
db dp[10005][1005];
int main()
{
    int k,q;
    scanf("%d%d",&k,&q);
    dp[0][0]=1.0;
    for(int i=1;i<=10000;i++)
        for(int j=0;j<=k;j++)
        {
            dp[i][j]+=dp[i-1][j]*j/k;
            dp[i][j+1]+=dp[i-1][j]*(k-j)/k;
        }
    for(int i=1;i<=q;i++)
    {
        int p;
        scanf("%d",&p);
        for(int j=0;j<=10000;j++)
            if(dp[j][k]>(p-eps)/2000)
            {
                printf("%d\n",j);
                break;
            }
    }
    return 0;
}