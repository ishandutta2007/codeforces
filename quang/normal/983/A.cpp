#include <bits/stdc++.h>

using namespace std;

int n;
long long a, b, c;

int main() {
    scanf("%d", &n);
    while (n--) {
        scanf("%I64d %I64d %I64d", &a, &b, &c);
        long long foo = __gcd(a, b);
        b /= foo;
        while (1) {
            long long bar = __gcd(b, c);
            if (bar == 1) {
                break;
            }
            while (b % bar == 0) {
                b /= bar;
            }
            c = bar;
        }
        if (b == 1) {
            puts("Finite");
        } else {
            puts("Infinite");
        }
    }
    return 0;
}