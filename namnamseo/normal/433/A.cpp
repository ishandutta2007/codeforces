#include <cstdio>
int n,a,i,b,x;
int main()
{
    scanf("%d",&n);
    for(;i<n;++i)scanf("%d",&x),(x==100?a:b)++;
    int i,j;
    for(i=0;i<=a;i++){
        for(j=0;j<=b;j++){
            if(i+2*j == a-i+2*b-2*j) break;
        }
        if(j<=b) break;
    }
    if(i<=a) puts("YES");
    else puts("NO");
    return 0;
}