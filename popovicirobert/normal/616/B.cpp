#include <cstdio>
#define INF 1000000000

int main(){
    int n,m,min,max,poz,i,j,nr;
    scanf("%d%d" ,&n,&m);
    max=0;
    for(i=0;i<n;i++){
        min=INF;
        for(j=0;j<m;j++){
            scanf("%d" ,&nr);
            if(nr<min)
                min=nr;
        }
        if(max<min)
            max=min;
    }
    printf("%d" ,max);
    return 0;
}