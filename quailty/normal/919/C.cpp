#include<bits/stdc++.h>
using namespace std;
const int MAXN=2005;
char str[MAXN][MAXN];
int tmp[MAXN][MAXN];
int main()
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++)
        scanf("%s",str[i]+1);
    int res=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            tmp[i][j]=(str[i][j]=='.');
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            tmp[i][j]+=tmp[i][j-1];
    for(int i=1;i<=n;i++)
        for(int j=k;j<=m;j++)
            res+=(tmp[i][j]-tmp[i][j-k]==k);
    if(k==1)return 0*printf("%d\n",res);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            tmp[i][j]=(str[i][j]=='.');
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            tmp[i][j]+=tmp[i-1][j];
    for(int i=k;i<=n;i++)
        for(int j=1;j<=m;j++)
            res+=(tmp[i][j]-tmp[i-k][j]==k);
    return 0*printf("%d\n",res);
}