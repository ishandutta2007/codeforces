#include <bits/stdc++.h>
using namespace std;

int main() {
    long long d, k, a, b, t;
    scanf ("%lld %lld %lld %lld %lld", &d, &k, &a, &b, &t);
    
    if (d <= k) return 0 * printf ("%lld\n", a * d);
    if (a * k + t >= b * k) return 0 * printf ("%lld\n", a * k + (d - k) * b);
    printf ("%lld\n", (d - d % k) * a + (d / k - 1) * t + min(t + d % k * a, d % k * b));
    return 0;
}