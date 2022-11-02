#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    long long n, a, b;
    scanf("%I64d %I64d %I64d", &n, &a, &b);
    n *= 6;
    if (a * b >= n) {
        printf("%I64d\n%I64d %I64d", a * b, a, b);
        return 0;
    }
    long long ans_a = 2e9, ans_b = 2e9, limit = sqrt(n) + 100;
    while (a <= limit) {
        long long need = max(b, (n + a - 1) / a);
        if (a * need <= ans_a * ans_b) ans_a = a, ans_b = need;
        a++;
    }
    while (b <= limit) {
        long long need = max(a, (n + b - 1) / b);
        if (need * b <= ans_a * ans_b) ans_a = need, ans_b = b;
        b++;
    }
    printf("%I64d\n%I64d %I64d", ans_a * ans_b, ans_a, ans_b);
    return 0;
}