#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=100005;
const int Mod=1000000007;
int dp[MAXN];
int main()
{
    int t,k;
    scanf("%d%d",&t,&k);
    for(int i=0;i<=k-1;i++)dp[i]=1;
    for(int i=k;i<=100000;i++)dp[i]=(dp[i-1]+dp[i-k])%Mod;
    for(int i=1;i<=100000;i++)dp[i]=(dp[i]+dp[i-1])%Mod;
    while(t--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        printf("%d\n",(dp[b]-dp[a-1]+Mod)%Mod);
    }
    return 0;
}