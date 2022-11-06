#include <cstdio>

int cnt[1001][1001];
char map[1001][1001];

int main()
{
    int n,m,k,i;
    scanf("%d%d%d",&n,&m,&k);
    for(i=1;i<=k;++i){
        scanf("%d%d",&n,&m);
        if(map[n][m]) continue;
        else map[n][m]=1;
        if( ++cnt[n-1][m-1]==4 ||
            ++cnt[n-1][m  ]==4 ||
            ++cnt[n  ][m-1]==4 ||
            ++cnt[n  ][m  ]==4) break;
    }
    if(i>k) i=0;
    printf("%d\n",i);
    return 0;
}