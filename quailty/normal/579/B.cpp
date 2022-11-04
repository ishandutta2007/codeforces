#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int a[805][805];
bool vis[805];
int ans[805];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=2;i<=2*n;i++)
        for(int j=1;j<i;j++)
            scanf("%d",&a[i][j]);
    for(int t=1;t<=n;t++)
    {
        int x,y,Max=0;
        for(int i=2;i<=2*n;i++)
            for(int j=1;j<i;j++)
                if(Max<a[i][j])
                {
                    if(vis[i]||vis[j])continue;
                    Max=a[i][j];
                    x=i;
                    y=j;
                }
        ans[x]=y;
        ans[y]=x;
        vis[x]=vis[y]=1;
    }
    for(int i=1;i<=2*n;i++)
        printf("%d ",ans[i]);
    return 0;
}