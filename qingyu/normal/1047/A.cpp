#include <bits/stdc++.h>

int main() {
    long long n;
    scanf("%lld", &n);
    if (n % 3) printf("1 2 %lld", n - 3);
    else printf("1 1 %lld", n - 2);
    return 0;
}