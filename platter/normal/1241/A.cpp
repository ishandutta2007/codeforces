#include <stdio.h>

int main(void) {
    int c;
    scanf("%d\n", &c);
    for(int t=0;t<c;t++) {
        int n;
        scanf("%d\n", &n);
        if (n==2) {
            printf("2\n");
        }
        else {
            printf("%d\n", n%2);
        }
    }
    return 0;
}