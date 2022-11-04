#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=505;
int a[MAXN],b[MAXN],dp[MAXN],pre[MAXN];
void output(int n)
{
    if(!n)return;
    output(pre[n]);
    printf("%d ",b[n]);
}
int main()
{
    int n,m;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
        scanf("%d",&b[i]);
    for(int i=1;i<=n;i++)
    {
        int k=0;
        for(int j=1;j<=m;j++)
        {
            if(a[i]==b[j] && dp[j]<dp[k]+1)
            {
                dp[j]=dp[k]+1;
                pre[j]=k;
            }
            else if(a[i]>b[j] && dp[j]>dp[k])k=j;
        }
    }
    int loc=0;
    for(int i=1;i<=m;i++)
        if(dp[i]>dp[loc])loc=i;
    printf("%d\n",dp[loc]);
    output(loc);
    return 0;
}