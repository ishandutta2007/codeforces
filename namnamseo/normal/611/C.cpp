#include <cstdio>

int n,m;
char d[510][510];
int down[510][510];
int right[510][510];

int main()
{
    scanf("%d%d",&n,&m);
    int i,j;
    for(i=1;i<=n;++i){
        scanf("%s",d[i]+1);
    }
    for(i=1;i<=n;++i){
        for(j=1;j<=m;++j){
            down[i][j]+=down[i][j-1]+down[i-1][j]-down[i-1][j-1];
            right[i][j]+=right[i][j-1]+right[i-1][j]-right[i-1][j-1];
            if(d[i][j]=='.' && d[i][j+1]=='.') ++right[i][j];
            if(d[i][j]=='.' && d[i+1][j]=='.') ++down[i][j];
        }
    }
    int q;
    scanf("%d",&q);
    int a,b,c,d;
    for(;q--;){
        scanf("%d%d%d%d",&a,&b,&c,&d);
        printf("%d\n",
            down[c-1][d]-down[a-1][d]-down[c-1][b-1]+down[a-1][b-1]+
            right[c][d-1]-right[a-1][d-1]-right[c][b-1]+right[a-1][b-1]);
    }
    return 0;
}