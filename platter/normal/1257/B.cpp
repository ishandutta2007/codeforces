#include <cstdio>

int main(void) {
    int c;
    scanf("%d\n", &c);
    for(int t=0;t<c;t++) {
        int x,y;
        scanf("%d %d\n", &x, &y);
        if (x>=y) {
            printf("YES\n");
            continue;
        }
        if (x==1) {
            printf("NO\n");
            continue;
        }
        if (x==2||x==3) {
            if (y==2||y==3) {
                printf("YES\n");
            }
            else {
                printf("NO\n");
            }
            continue;
        }
        printf("YES\n");
    }
    return 0;
}