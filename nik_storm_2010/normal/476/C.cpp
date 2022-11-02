#include <cstdio>

using namespace std;
const int MOD = 1e9 + 7;

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    long long ans = 0, sum = ((1LL + a) * a / 2) % MOD;
    for (int i = 1; i < b; i++) ans = (ans + ((i * sum) % MOD) * b + (long long)i * a) % MOD;
    printf("%I64d\n", ans);
    return 0;
}