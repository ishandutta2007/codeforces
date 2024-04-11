#include <stdio.h>
 
int digit(int n, int ord) {
    for(int k=0;k<ord;k++) {
        n=n/10;
    }
    return n%10;
}
 
int length(int n) {
    int a=0;
    while(n!=0) {
        n=n/10;
        a+=1;
    }
    return a;
}
 
int main(void) {
    int a,b;
    scanf("%d %d", &a, &b);
    for(int i=a;i<=b;i++) {
        int pass=1;
        int g[10]={};
        for(int j=0;j<length(i);j++) {
            if (g[digit(i,j)]==1) {
                pass=0;
                break;
            }
            g[digit(i,j)]=1;
        }
        if (pass==1) {
            printf("%d", i);
            return 0;
        }
    }
    printf("-1");
    return 0;
}