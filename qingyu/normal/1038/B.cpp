#include <bits/stdc++.h>

inline long long gcd(long long x, long long y) { return y ? gcd(y, x % y) : x; }

long long n, sum;

inline void output(long long A, long long B) {
    if (A > B) output(B, A);
    else {
        printf("Yes\n1 %lld\n%lld", A, n - 1);
        for (long long i = 1; i <= n; ++i) if(i != A) printf(" %lld", i);
    }
}

int main() {
    scanf("%lld", &n);
    sum = n * (n + 1) / 2;
    for (long long A = 1; A <= sum / 2; ++A)
        if (gcd(sum - A, A) > 1) {
            output(A, sum - A);
            return 0;
        }
    printf("No");
    return 0;
}