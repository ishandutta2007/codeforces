#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
ll w,m,f[20]={1};
int p=0;
bool isok=0;
void dfs(int now,ll tot,int cnt)
{
    if(cnt==p+1)
    {
        if(tot==m)isok=1;
        return;
    }
    dfs(now*w,tot+now,cnt+1);
    dfs(now*w,tot,cnt+1);
    dfs(now*w,tot-now,cnt+1);
}
int main()
{
    scanf("%I64d%I64d",&w,&m);
    if(w<=3)printf("YES\n");
    else
    {
        ll t=1;
        while(t<m)
        {
            t*=w;
            p++;
        }
        dfs(1,0,0);
        if(isok)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}