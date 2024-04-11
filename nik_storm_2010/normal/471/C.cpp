#include <cstdio>

using namespace std;

int main() {
    long long n, base = 0;
    scanf("%I64d", &n);
    int ans = 0;
    for (int i = 1; ; i++) {
        base += 2 * i + i - 1;
        if (base > n) break;
        ans += ((n - base) % 3 == 0);
    }
    printf("%d\n", ans);
    return 0;
}