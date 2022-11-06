#include <cstdio>

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int i,j;
    for(i=0;i<n;++i){
        for(j=0;j<m;++j){
            putchar((i%2==0 || ((i%4==1 && j==m-1) || (i%4==3 && j==0)))?'#':'.');
        }
        putchar(10);
    }
    return 0;
}