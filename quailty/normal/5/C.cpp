#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=1000005;
char s[MAXN];
int dp[MAXN],stk[MAXN],top;
int main()
{
    scanf("%s",s);
    for(int i=0;s[i];i++)
    {
        if(s[i]=='(')
        {
            stk[top++]=i;
            dp[i]=-1;
        }
        else
        {
            if(top==0)dp[i]=-1;
            else
            {
                dp[i]=stk[--top];
                if(dp[i]>0 && s[dp[i]-1]==')' && dp[dp[i]-1]>=0)
                    dp[i]=dp[dp[i]-1];
            }
        }
    }
    int len=0,cnt=1;
    for(int i=0;s[i];i++)
        if(dp[i]>=0)
        {
            if(i-dp[i]+1>len)len=i-dp[i]+1,cnt=0;
            if(i-dp[i]+1==len)cnt++;
        }
    printf("%d %d\n",len,cnt);
    return 0;
}