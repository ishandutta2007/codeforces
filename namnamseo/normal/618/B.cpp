#include <cstdio>

int n;
int table[51][51];

int ans[51];

int main()
{
    scanf("%d",&n);
    int i,j;
    for(i=1;i<=n;++i) for(j=1;j<=n;++j) scanf("%d",table[i]+j);
    int x;
    for(x=1; x<=n; ++x){
        for(i=1;i<=n;++i){
            bool exist=0;
            for(j=1;j<=n;++j){
                if(table[i][j]!=0){
                    exist=1;
                    if(table[i][j]!=1) break;
                }
            }
            if(exist && j>n) break;
        }
        if(i<=n){
            ans[i]=x;
        }
        for(i=1;i<=n;++i) for(j=1;j<=n;++j) if(table[i][j]) --table[i][j];
    }
    for(i=1;i<=n;++i) {
        if(ans[i]==0) ans[i]=n;
        printf("%d ",ans[i]);
    }
    return 0;
}