#include <stdio.h>

int main(void) {
    int c;
    scanf("%d\n", &c);
    for(int t=0;t<c;t++) {
        int tn,hn;
        scanf("%d %d\n", &tn, &hn);
        int a,b;
        int kgmax=-1000000000;
        int kmax=0;
        for(int i=0;i<tn;i++) {
            scanf("%d %d\n", &a, &b);
            if (a-b>kgmax) {
                kgmax=a-b;
            }
            if (a>kmax) {
                kmax=a;
            }
        }
        if (kmax>=hn) {
            printf("1\n");
        }
        else if (kgmax<=0) {
            printf("-1\n");
        }
        else {
            printf("%d\n", ((hn-kmax-1)/kgmax)+2);
        }
    }
    return 0;
}