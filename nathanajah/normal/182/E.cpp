#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
#include <stdlib.h>
#include <map>
#include <stack>
#include <queue>
#include <deque>
using namespace std;

int n,l;
int a[200];
int b[200];
int i,j,k;
int dp[3005][105][2];
int res;

int hitung(int l, int ti, int flip)
{
    if (l<0)
        return 0;
    int &ret=dp[l][ti][flip];
    if (ret>=0)
        return ret;
    if (a[ti]==b[ti] && flip==1)
        return 0;
    ret=0;
    int i;
    int lengthnow;
    if (flip==0)
        lengthnow=a[ti];
    else
        lengthnow=b[ti];
    for (i=0;i<n;++i)
    {
        if (i!=ti && a[i]==lengthnow)
            ret=(ret+hitung(l-lengthnow,i,1))%1000000007;
        if (i!=ti && b[i]==lengthnow)
            ret=(ret+hitung(l-lengthnow,i,0))%1000000007;
    }
    return ret;
}
int main()
{
    memset(dp,-1,sizeof(dp));
    scanf("%d %d",&n,&l);
    for (i=0;i<n;++i)
    {
        scanf("%d %d",&a[i],&b[i]);
        dp[a[i]][i][0]=1;
        if (a[i]!=b[i])
            dp[b[i]][i][1]=1;
        else
            dp[b[i]][i][1]=0;
    }
    for (i=0;i<n;++i)
    {
        res=(res+hitung(l,i,0))%1000000007;
        res=(res+hitung(l,i,1))%1000000007;
    }
    printf("%d\n",res);
}