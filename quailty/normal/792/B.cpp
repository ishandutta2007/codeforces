#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int a[105],vis[105];
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=k;i++)
        scanf("%d",&a[i]);
    int f=1;
    for(int i=1;i<=k;i++)
    {
        a[i]%=(n-i+1);
        for(int j=0;j<a[i];j++)
        {
            f=f%n+1;
            while(vis[f])f=f%n+1;
        }
        vis[f]=1;
        printf("%d ",f);
        while(vis[f])f=f%n+1;
    }
    return 0;
}