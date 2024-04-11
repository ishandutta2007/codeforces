#include <cstdio>

int main(void) {
    int c;
    scanf("%d\n",&c);
    for(int t=0;t<c;t++) {
        int l,r,d;
        scanf("%d %d %d\n",&l,&r,&d);
        if (l>d) {
            printf("%d\n",d);
        }
        else {
            printf("%d\n",(r/d)*d+d);
        }
    }
    return 0;
}