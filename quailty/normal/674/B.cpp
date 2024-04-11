#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
bool vis[1005];
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    int a,b,c,d;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    vis[a]=1;
    vis[b]=1;
    vis[c]=1;
    vis[d]=1;
    if(n==4)return 0*printf("-1");
    if(k<=n)return 0*printf("-1");
    int fi,la;
    for(int i=1;i<=n;i++)
        if(!vis[i])
        {
            fi=i;
            break;
        }
    for(int i=n;i>=1;i--)
        if(!vis[i])
        {
            la=i;
            break;
        }
    printf("%d %d ",a,c);
    for(int i=1;i<=n;i++)
        if(!vis[i])printf("%d ",i);
    printf("%d %d\n",d,b);
    printf("%d %d %d ",c,a,fi);
    for(int i=1;i<=n;i++)
        if(i!=fi && i!=la && !vis[i])printf("%d ",i);
    if(fi!=la)printf("%d ",la);
    printf("%d %d\n",b,d);
    return 0;
}