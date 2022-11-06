#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

i64 gcd(i64 a, i64 b) {
    while (b) {
        i64 t = a % b;
        a = b;
        b = t;
    }
    return a;
}

i64 phi(i64 m) {
    i64 phi = m;
    for (i64 i = 2; i * i <= m; i ++) {
        if (m % i == 0) {
            phi = phi / i * (i - 1);
            for (; m % i == 0; m /= i);
        }
    }
    if (m > 1) {
        phi = phi / m * (m - 1);
    }
    return phi;
}

int main() {
    i64 T, a, m;
    scanf("%lld", &T);
    while (T --) {
        scanf("%lld%lld", &a, &m);
        i64 d = gcd(a, m);
        m /= d;
        i64 res = phi(m);
        printf("%lld\n", res);
    }
    return 0;
}