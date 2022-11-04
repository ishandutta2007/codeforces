#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int a[55][55];
bool vis[55];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    int loc=0;
    for(int i=1;i<=n;i++)
    {
        memset(vis,0,sizeof(vis));
        for(int j=1;j<=n;j++)
            vis[a[i][j]]=1;
        bool flag=1;
        for(int j=1;j<n;j++)
            if(!vis[j])flag=0;
        if(flag)
        {
            loc=i;
            break;
        }
    }
    for(int j=1;j<=n;j++)
        printf("%d ",a[loc][j]==0 ? n : a[loc][j]);
    return 0;
}