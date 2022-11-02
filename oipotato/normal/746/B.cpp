#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int main()
{
    int n;scanf("%d",&n);
    char s[2010],t[2010];
    scanf("%s",s+1);
    int l=(n+1)/2,r=(n+1)/2,now=1;
    t[l]=s[now];
    if(!(n&1))t[++r]=s[++now];
    for(;now<=n;)
    {
        t[--l]=s[++now];
        if(now>n)break;
        t[++r]=s[++now];
    }
    t[r+1]=0;
    puts(t+1);
    return 0;
}