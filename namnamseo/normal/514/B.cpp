#include <cstdio>

int x[1010];
int y[1010];
int n;

int main()
{
    int x0,y0;
    scanf("%d%d%d",&n,&x0,&y0);
    int i,j,ans=0;
    for(i=0;i<n;++i){
        scanf("%d%d",x+i,y+i);
        x[i]-=x0; y[i]-=y0;
        for(j=0;j<i;++j){
            if(x[i]*y[j]==x[j]*y[i]) break;
        }
        if(j==i) ++ans;
    }
    printf("%d",ans);
    return 0;
}