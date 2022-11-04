#include<bits/stdc++.h>
using namespace std;
const int MAXN=200005;
char str[MAXN];
int dp[MAXN],fp[MAXN];
int main()
{
    scanf("%s",str+1);
    int n=strlen(str+1);
    reverse(str+1,str+n+1);
    fp[1]=fp[2]=-MAXN;
    for(int i=1,s=0;i<=n;i++)
    {
        s=(s+str[i]-'0')%3;
        if(str[i]=='0')dp[i]=dp[i-1]+1;
        else dp[i]=max(dp[i-1],fp[s]+1);
        fp[s]=max(fp[s],dp[i]);
    }
    printf("%d\n",dp[n]);
    return 0;
}