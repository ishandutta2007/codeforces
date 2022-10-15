#include <bits/stdc++.h>

using namespace std;

int const INF = 1 << 30;

int const N = 1234567;

int a[N];

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    map<int, int> f, g;
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    for (int i = 0; i < n; i++) g[a[i]]++;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        g[a[i]]--;
        if (a[i] % k == 0) {
            int y = a[i] / k;
            long long zz = (long long) a[i] * k;
            if (-INF <= zz && zz <= INF) {
                int z = (int) zz;
                ans += (long long) f[y] * g[z];
            }
        }
        f[a[i]]++;
    }
    printf("%I64d\n", ans);
}