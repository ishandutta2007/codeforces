#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=100005;
char s[MAXN],t[MAXN];
int ok[MAXN],fail[MAXN],dp[MAXN][2];
void get_fail(int n,char *str)
{
    fail[1]=0;
    for(int i=1;i<n;i++)
    {
        int p=fail[i];
        while(p && str[i+1]!=str[p+1])p=fail[p];
        fail[i+1]=p+(str[i+1]==str[p+1]);
    }
}
int main()
{
    scanf("%s%s",s+1,t+1);
    int n=strlen(s+1),m=strlen(t+1);
    for(int i=m;i<=n;i++)
    {
        ok[i]=1;
        for(int j=1,k=i-m+1;j<=m;j++,k++)
            if(s[k]!='?' && s[k]!=t[j])ok[i]=0;
    }
    get_fail(m,t);
    for(int i=m;i<=n;i++)
    {
        if(ok[i])
        {
            int t=m;
            while(t)
            {
                int len=m-fail[t];
                dp[i][1]=max(dp[i][1],dp[i-len][1]+1);
                t=fail[t];
            }
            dp[i][1]=max(dp[i][1],dp[i-m][0]+1);
        }
        dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
    }
    return 0*printf("%d",max(dp[n][0],dp[n][1]));
}