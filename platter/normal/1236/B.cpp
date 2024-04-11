#include <stdio.h>

long long madepow(long long a, int b) {
    if (b==0)
    return 1;
    if (b%2==1)
    return (madepow(a,b-1)*a)%1000000007;
    long long half=madepow(a,b/2);
    if (b%2==0)
    return (half*half)%1000000007;
}

int main(void) {
    int n,m;
    scanf("%d %d", &n, &m);
    long long x=madepow(2,m)-1;
    printf("%lld", madepow(x,n));
    return 0;
}