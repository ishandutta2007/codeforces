#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int a[1005][1005];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&a[i][j]);
    int res=0;
    for(int i=1;i<=n;i++)
    {
        int now=0;
        for(int j=1;j<=m;j++)
        {
            if(a[i][j]==1)now=1;
            else res+=now;
        }
    }
    for(int i=1;i<=n;i++)
    {
        int now=0;
        for(int j=m;j>=1;j--)
        {
            if(a[i][j]==1)now=1;
            else res+=now;
        }
    }
    for(int j=1;j<=m;j++)
    {
        int now=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i][j]==1)now=1;
            else res+=now;
        }
    }
    for(int j=1;j<=m;j++)
    {
        int now=0;
        for(int i=n;i>=1;i--)
        {
            if(a[i][j]==1)now=1;
            else res+=now;
        }
    }
    return 0*printf("%d",res);
}