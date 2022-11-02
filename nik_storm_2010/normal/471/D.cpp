#include <cstdio>

using namespace std;
typedef unsigned long long ull;
const int N = 5e5 + 10;
const int INF = 2e9;

int a[N], b[N], s[N], p[N];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= m; i++) scanf("%d", &b[i]);
    if (m > n) {
        puts("0");
        return 0;
    }
    if (m == 1) {
        printf("%d\n", n);
        return 0;
    }
    for (int i = 1; i < m; i++) s[i] = b[i] - b[i + 1];
    s[m] = INF;
    for (int i = 1; i < n; i++) s[m + i] = a[i] - a[i + 1];
    int ans = 0;
    for (int i = 2; i < n + m; i++) {
        p[i] = p[i - 1];
        while (p[i] > 0 && s[i] != s[p[i] + 1]) p[i] = p[p[i]];
        if (s[i] == s[p[i] + 1]) p[i]++;
        if (p[i] == m - 1) ans++;
    }
    printf("%d\n", ans);
    return 0;
}