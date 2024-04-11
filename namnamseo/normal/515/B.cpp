#include <cstdio>

int n,m;
bool happy[2][101];

int main()
{
    scanf("%d%d",&n,&m);
    int i;
    int t;
    int j;
    for(j=0;j<2;++j){
        scanf("%d",&t);
        for(;t--;) scanf("%d",&i),happy[j][i]=true;
    }
    for(i=0;i<=10000;++i){
        if(happy[0][i%n] || happy[1][i%m]){
            happy[0][i%n]=true;
            happy[1][i%m]=true;
        }
    }
    for(i=0;i<n;++i) if(!happy[0][i]) goto no;
    for(i=0;i<m;++i) if(!happy[1][i]) goto no;
    puts("Yes");
    return 0;
    no:
        puts("No");
    return 0;
}