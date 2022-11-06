#include <cstdio>
int c[2];
int main()
{
    int n,buf;
    scanf("%d",&n);
    for(;n--;) scanf("%d",&buf),++c[buf/5];
    if(c[1]<9){
        if(c[0]) puts("0");
        else puts("-1");
    } else {
        if(c[0]){
            c[1]/=9;
            int i;
            for(;c[1]--;) printf("555555555");
            for(;c[0]--;) printf("0");
        } else puts("-1");
    }
    putchar(10);
    return 0;
}