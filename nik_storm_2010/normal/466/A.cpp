#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int n, m, a, b;
    scanf("%d %d %d %d", &n, &m, &a, &b);
    int ans = n * a;
    ans = min(ans, (n + m - 1) / m * b);
    ans = min(ans, (n / m) * b + (n - n / m * m) * a);
    printf("%d\n", ans);
}