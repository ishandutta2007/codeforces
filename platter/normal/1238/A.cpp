#include <stdio.h>
 
int main(void) {
    int c;
    scanf("%d\n", &c);
    for(int t=0;t<c;t++) {
        long long x,y;
        scanf("%lld %lld\n", &x, &y);
        if (x-y==1)
        printf("NO\n");
        else 
        printf("YES\n");
    }
    return 0;
}