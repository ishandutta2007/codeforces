#include <cstdio>

int main(){
    int i,n,m,x,min,l,r;
    scanf("%d%d" ,&n,&m);
    min=1000000000;
    for(i=1;i<=m;i++){
        scanf("%d%d" ,&l,&r);
        if(min>r-l+1)
             min=r-l+1;
    }
    printf("%d\n" ,min);
    x=0;
    for(i=1;i<=n;i++){
        printf("%d " ,x);
        x++;
        if(x==min)
             x=0;
    }
    return 0;
}