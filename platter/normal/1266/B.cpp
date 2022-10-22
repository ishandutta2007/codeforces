#include <cstdio>

int main(void) {
    int c;
    scanf("%d\n",&c);
    for(int t=0;t<c;t++) {
        long long n;
        scanf("%lld",&n);
        if (n>14&&n%14>0&&n%14<=6) {
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }
    }
    return 0;
}