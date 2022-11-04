#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=1000005;
const int Mod=1000000007;
int a[MAXN],dp[MAXN];
void add(int &x,int y)
{
    if((x+=y)>=Mod)x-=Mod;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        a[i]--;
    }
    int res=a[1];
    for(int i=2;i<=n;i++)
    {
        dp[i]=1LL*dp[i-1]*min(a[i-2],min(a[i-1],a[i]))%Mod;
        add(dp[i],min(a[i-1],a[i]));
        add(res,1LL*dp[i]*min(a[i],a[i-1])%Mod);
        add(res,a[i]);
    }
    return 0*printf("%d\n",res);
}