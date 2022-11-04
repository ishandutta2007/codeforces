#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=5005;
int a[MAXN],dp[MAXN],l[MAXN],r[MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<MAXN;i++)
        l[i]=n+1,r[i]=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        l[a[i]]=min(l[a[i]],i);
        r[a[i]]=max(r[a[i]],i);
    }
    for(int i=1;i<=n;i++)
    {
        dp[i]=max(dp[i],dp[i-1]);
        int now=0,lef=i,rig=i;
        for(int j=i;j>0 && lef<=j;j--)
        {
            lef=min(lef,l[a[j]]);
            rig=max(rig,r[a[j]]);
            if(l[a[j]]==j)now^=a[j];
        }
        if(rig==i)dp[i]=max(dp[i],dp[lef-1]+now);
    }
    return 0*printf("%d",dp[n]);
}