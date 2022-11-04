#include <cstdio>

int main(){
    int n,i,sum,con,b,d,x;
    scanf("%d%d%d" ,&n,&b,&d);
    sum=0;
    con=0;
    for(i=1;i<=n;i++){
        scanf("%d" ,&x);
        if(x<=b){
            sum+=x;
            if(sum>d){
               con++;
               sum=0;
            }
        }
    }
    printf("%d" ,con);
    return 0;
}