#include<bits/stdc++.h>
using namespace std;
const int MAXN=105;
int a[MAXN],b[MAXN],c[MAXN][MAXN];
int main()
{
    int n,m,h;
    scanf("%d%d%d",&n,&m,&h);
    for(int i=1;i<=m;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        scanf("%d",&b[i]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&c[i][j]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            c[i][j]*=min(a[j],b[i]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            printf("%d%c",c[i][j]," \n"[j==m]);
    return 0;
}