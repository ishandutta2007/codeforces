#include <cstdio>

int table[501][501];

int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    int a=n*n;
    int i,j;
    int ans=0;
    for(i=1;i<=n;++i){
        for(j=n;j>=k;--j){
            table[i][j]=a--;
        }
        ans+=table[i][k];
    }
    for(i=1;i<=n;++i) for(j=k-1;j>=1;--j) table[i][j]=a--;
    printf("%d\n",ans);
    for(i=1;i<=n;++i,putchar(10)) for(j=1;j<=n;++j) printf("%d ",table[i][j]);
    return 0;
}