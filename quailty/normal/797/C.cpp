#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=100005;
char s[MAXN],dp[MAXN],stk[MAXN],res[MAXN];
int main()
{
    scanf("%s",s);
    int n=strlen(s);
    dp[n]='z'+1;
    for(int i=n-1;i>=0;i--)
        dp[i]=min(dp[i+1],s[i]);
    for(int i=0,j=0,k=0;i<=n;i++)
    {
        while(k>0 && dp[i]>=stk[k-1])
            res[j++]=stk[k-1],k--;
        stk[k++]=s[i];
    }
    return 0*printf("%s\n",res);
}