#include<bits/stdc++.h>
using namespace std;
const int MAXN=40005;
const int Mod=1000000007;
int dp[MAXN];
void init()
{
    dp[0]=1;
    for(int i=1;i<MAXN;i++)
    {
        int t=i,r=0;
        while(t)r=r*10+t%10,t/=10;
        if(r!=i)continue;
        for(int j=i;j<MAXN;j++)
            dp[j]=(dp[j]+dp[j-i])%Mod;
    }
}
int main()
{
    init();
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        printf("%d\n",dp[n]);
    }
    return 0;
}