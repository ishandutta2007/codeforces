#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=8005;
const int INF=0x3f3f3f3f;
inline void kmp(char str[],int fail[],int n)
{
    fail[1]=0;
    for(int i=1;i<n;i++)
    {
        int p=fail[i];
        while(p && str[p+1]!=str[i+1])p=fail[p];
        fail[i+1]=p+(str[p+1]==str[i+1]);
    }
}
inline int num(int x)
{
    int res=0;
    while(x)x/=10,res++;
    return res;
}
char s[MAXN];
int dp[MAXN],nxt[MAXN];
int main()
{
    scanf("%s",s+1);
    int n=strlen(s+1);
    memset(dp+1,INF,n*sizeof(int));
    for(int i=1;i<=n;i++)
    {
        kmp(s+i-1,nxt,n+1-i);
        for(int j=i;j<=n;j++)
        {
            int t=(j-i+1)-nxt[j-i+1],d;
            if((j-i+1)%t==0)d=(j-i+1)/t;
            else d=1;
            dp[j]=min(dp[j],dp[i-1]+(j-i+1)/d+num(d));
        }
    }
    return 0*printf("%d\n",dp[n]);
}