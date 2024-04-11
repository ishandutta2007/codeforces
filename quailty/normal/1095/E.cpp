#include<bits/stdc++.h>
using namespace std;
char s[1000005];
int pre[1000005],suf[1000005];
int main()
{
    int n,res=0;
    scanf("%d%s",&n,s+1);
    int sum=0;
    for(int i=1;i<=n;i++)
        sum+=(s[i]=='(' ? 1 : -1);
    int now=0;
    for(int i=1;i<=n;i++)
        pre[i]=min(pre[i-1],now+=(s[i]=='(' ? 1 : -1));
    now=0;
    for(int i=n;i>=1;i--)
        suf[i]=min(suf[i+1],now+=(s[i]=='(' ? -1 : 1));
    if(sum==2)for(int i=1;i<=n;i++)
        res+=(s[i]=='(' && pre[i-1]==0 && suf[i+1]==0);
    if(sum==-2)for(int i=1;i<=n;i++)
        res+=(s[i]==')' && pre[i-1]==0 && suf[i+1]==0);
    printf("%d\n",res);
    return 0;
}