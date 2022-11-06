#include <cstdio>
int t[11][11];
int main()
{
    int n;
    scanf("%d",&n);
    int i,j;
    for(i=1;i<=n;++i) t[1][i]=1, t[i][1]=1;
    for(i=2;i<=n;++i) for(j=2;j<=n;++j) t[i][j]=t[i][j-1]+t[i-1][j];
    printf("%d\n",t[n][n]);
    return 0;
}