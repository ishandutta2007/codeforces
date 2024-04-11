#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=5005;
int tr[MAXN],tc[MAXN];
int cr[MAXN],cc[MAXN];
int main()
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=k;i++)
    {
        int ty;
        scanf("%d",&ty);
        if(ty==1)
        {
            int r,a;
            scanf("%d%d",&r,&a);
            tr[r]=i;
            cr[r]=a;
        }
        else
        {
            int c,a;
            scanf("%d%d",&c,&a);
            tc[c]=i;
            cc[c]=a;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(tr[i]>tc[j])printf("%d ",cr[i]);
            else printf("%d ",cc[j]);
        }
        printf("\n");
    }
    return 0;
}