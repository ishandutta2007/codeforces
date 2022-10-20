#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long n, ans, a, b, c;
    scanf("%lld", &n);
    for (long long i=0;i<n;i++){
        scanf("%lld %lld %lld", &a, &b, &c);
        printf("%lld\n", a+b+c-1);
    }
    return 0;
}