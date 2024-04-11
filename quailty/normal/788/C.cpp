#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<bitset>
using namespace std;
const int o=1000;
int a[1005];
bitset<2001>dp[2];
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1,t;i<=k;i++)
    {
        scanf("%d",&t);
        a[t]=1;
    }
    int now=0,la=1;
    dp[now][o]=1;
    int res;
    for(res=1;res<=1000;res++)
    {
        swap(now,la);
        dp[now].reset();
        for(int i=0;i<=1000;i++)
            if(a[i])dp[now]|=(dp[la]<<i)>>n;
        if(dp[now][o])break;
    }
    return 0*printf("%d",(res<=1000 ? res : -1));
}