#include <cstdio>
 
int main(void) {
    int c;
    scanf("%d\n", &c);
    for(int t=0;t<c;t++) {
        long long a,b;
        scanf("%lld %lld\n", &a, &b);
        if (a>2*b||b>2*a) {
            printf("NO\n");
            continue;
        }
        if ((a+b)%3==0) {
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }
    }
    return 0;
}