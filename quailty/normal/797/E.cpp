#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=100005;
const int BLK=325;
int a[MAXN],dp[BLK][MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int k=1;k<BLK;k++)
        for(int i=n;i>=1;i--)
        {
            int j=i+a[i]+k;
            dp[k][i]=(j<=n ? dp[k][j] : 0)+1;
        }
    int q;
    scanf("%d",&q);
    for(int i=1;i<=q;i++)
    {
        int p,k;
        scanf("%d%d",&p,&k);
        if(k>=BLK)
        {
            int res=0;
            while(p<=n)p=p+a[p]+k,res++;
            printf("%d\n",res);
        }
        else printf("%d\n",dp[k][p]);
    }
    return 0;
}