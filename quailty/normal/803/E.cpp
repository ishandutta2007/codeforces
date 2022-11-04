#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=1005;
const char go[]="WDL";
char s[MAXN],r[MAXN];
int dp[MAXN][MAXN*2];
pair<int,int> pre[MAXN][MAXN*2];
int main()
{
    int n,k;
    scanf("%d%d%s",&n,&k,s+1);
    dp[0][0+MAXN]=1;
    for(int i=1;i<=n;i++)
        for(int j=-k+MAXN;j<=k+MAXN;j++)
        {
            if(!dp[i-1][j])continue;
            for(int t=0;t<3;t++)
            {
                if(s[i]!='?' && s[i]!=go[t])continue;
                int g=(j-MAXN)+1-t;
                if(g>=k+(i==n) || g<=-k-(i==n))continue;
                dp[i][g+MAXN]=1;
                pre[i][g+MAXN]=make_pair(j,t);
            }
        }
    int now=-1;
    if(dp[n][k+MAXN])now=k+MAXN;
    if(dp[n][-k+MAXN])now=-k+MAXN;
    if(now<0)return 0*printf("NO");
    for(int i=n;i>0;i--)
    {
        r[i]=go[pre[i][now].second];
        now=pre[i][now].first;
    }
    return 0*printf("%s",r+1);
}