#include <bits/stdc++.h>
using namespace std;

int ctz(long long n) {
    // if (n == 0) return 0;
    return __builtin_ctzll(n);
}

int main() {
    long long n;
    scanf("%lld", &n);
    
    int msb = 0;
    while (n >> msb++);
    
    long long l, r;
    scanf("%lld %lld", &l, &r);
    
    int ans = 0;
    for (long long i=l; i<=r; i++) {        
        ans += n >> msb - __builtin_ctzll(i) - 2 & 1;
    }
    printf("%d\n", ans);
    return 0;
}