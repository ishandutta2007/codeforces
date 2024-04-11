#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
char s[25][155];
int n,m,res,l[25],r[25];
void dfs(int dep,int up,int lr,int now)
{
    if(dep==up)
    {
        if(lr==0)res=min(res,now+r[dep]);
        else res=min(res,now+m+1-l[dep]);
        return;
    }
    dfs(dep-1,up,lr^1,now+m+2);
    if(lr==0)dfs(dep-1,up,lr,now+2*r[dep]+1);
    else dfs(dep-1,up,lr,now+2*(m+1-l[dep])+1);
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%s",s[i]);
    int up=-1;
    for(int i=0;i<n;i++)
    {
        bool flag=0;
        for(int j=0;j<m+2;j++)
            if(s[i][j]=='1')r[i]=j,flag=1;
        for(int j=m+1;j>=0;j--)
            if(s[i][j]=='1')l[i]=j,flag=1;
        if(flag && up<0)up=i;
        if(!flag)l[i]=m+1,r[i]=0;
    }
    if(up<0)return 0*printf("0");
    res=n*(m+2);
    dfs(n-1,up,0,0);
    return 0*printf("%d",res);
}