#include <cstdio>
int a,b;main(){
    while((a=getchar())>=48){
        a-=48;
        if(a!=9 || b) if(a>=5) a=9-a;
        b=1;
        putchar(a+48);
    }
    return 0;
}