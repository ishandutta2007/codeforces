#include<cstdio>
#include<algorithm>

using namespace std;

pair <int,int> a[200000];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) scanf("%d %d", &a[i].second, &a[i].first);
    sort(a, a + m);
    long long ans = 0;
    for (int i = 1; i <= m; i++) {
        long long need = (i * (i - 1LL) / 2) + 1;
        if (i % 2 == 0) need += i / 2 - 1;
        if (need <= n) ans += a[m - i].first;
    }
    printf("%I64d\n", ans);
    return 0;
}