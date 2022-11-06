#include <cstdio>

int n;

int mat[101][101];
int ans[101];

int main()
{
    scanf("%d",&n);
    int i,j,flg, top=0;
    for(i=0;i<n;++i){
        for(flg=1,j=0;j<n;++j) {
            scanf("%d",mat[i]+j);
            if(mat[i][j]==1 || mat[i][j]==3) flg=0;
        }
        if(flg) ans[top++]=i+1;
    }
    printf("%d\n",top);
    for(j=0;j<top;++j) printf("%d ",ans[j]); putchar(10);
    return 0;
}