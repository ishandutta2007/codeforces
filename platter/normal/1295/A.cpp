#include <cstdio>

int main(void) {
    int c;
    scanf("%d\n",&c);
    for(int t=0;t<c;t++) {
        int n;
        scanf("%d\n",&n);
        if (n%2==1) {
            printf("7");
        }
        else {
            printf("1");
        }
        for(int i=1;i<n/2;i++) {
            printf("1");
        }
        printf("\n");
    }
    return 0;
}