#include <cstdio>

int main(void) {
    int n;
    scanf("%d", &n);
    for(int key=1;key<=n;key++) {
        int change=0;
        for(int base=0;base<n*n;base+=n) {
            if (change==0) {
                printf("%d ", base+key);
            }
            if (change==1) {
                printf("%d ", base+n-key+1);
            }
            change=1-change;
        }
        printf("\n");
    }
    return 0;
}