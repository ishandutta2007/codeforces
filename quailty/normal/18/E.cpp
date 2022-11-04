#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=505;
const int INF=0x3f3f3f3f;
char s[505][505];
int dp[505][705],pre[505][705],cost[505][705];
void output(int n,int m,int k)
{
    if(!n)return;
    output(n-1,m,pre[n][k]);
    for(int i=0;i<m;i++)
    {
        if(i%2==0)printf("%c",'a'+k/26);
        else printf("%c",'a'+k%26);
    }
    printf("\n");
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%s",s[i]);
    for(int i=1;i<=n;i++)
        for(int j=0;j<26;j++)
            for(int k=0;k<26;k++)
                for(int l=0;l<m;l++)
                {
                    if(l%2==0 && s[i][l]!=j+'a')cost[i][j*26+k]++;
                    if(l%2==1 && s[i][l]!=k+'a')cost[i][j*26+k]++;
                }
    memset(dp,INF,sizeof(dp));
    memset(dp[0],0,sizeof(dp[0]));
    for(int i=1;i<=n;i++)
        for(int j=0;j<26*26;j++)
            for(int k=0;k<26*26;k++)
                if(k/26!=k%26 && k/26!=j/26 && k%26!=j%26)
                    if(dp[i][k]>dp[i-1][j]+cost[i][k])
                    {
                        dp[i][k]=dp[i-1][j]+cost[i][k];
                        pre[i][k]=j;
                    }
    int loc=0;
    for(int i=0;i<26*26;i++)
        if(dp[n][loc]>dp[n][i])loc=i;
    printf("%d\n",dp[n][loc]);
    output(n,m,loc);
    return 0;
}