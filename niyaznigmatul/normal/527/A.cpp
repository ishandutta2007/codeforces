#include <bits/stdc++.h>

using namespace std;


int main() {
    long long a, b;
    scanf("%lld%lld", &a, &b);
    long long ans = 0;
    while (b != 0) {
        ans += a / b;
        long long t = a % b;
        a = b;
        b = t;
    }
    printf("%lld\n", ans);
}