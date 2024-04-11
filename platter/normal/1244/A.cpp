#include <stdio.h>
 
int main(void) {
    int n;
    scanf("%d\n", &n);
    for(int t=0;t<n;t++) {
        int a,b,c,d,k;
        scanf("%d %d ", &a, &b);
        scanf("%d %d %d\n", &c, &d, &k);
        a--;
        int pen;
        pen=(a/c)+1;
        b--;
        int pencil;
        pencil=(b/d)+1;
        if (pen+pencil>k) {
            printf("-1\n");
        }
        else {
            printf("%d %d\n", pen, pencil);
        }
    }
    return 0;
}