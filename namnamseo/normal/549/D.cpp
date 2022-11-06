#include <cstdio>

int n,m;

char x[111][111];
int tb[111][111];

int tg(char x){
    return x=='B'?-1:1;
}

int main()
{
    scanf("%d%d",&n,&m);
    int i,j,k,l,df;
    int ans=0;
    for(i=0;i<n;++i) scanf("%s",x[i]);
    for(i=n-1;0<=i;--i){
        for(j=m-1;0<=j;--j){
            df=tg(x[i][j])-tb[i][j];
            if(df) ++ans;
            for(k=0;k<=i;++k){
                for(l=0;l<=j;++l){
                    tb[k][l]+=df;
                }
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}