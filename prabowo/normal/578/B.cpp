#include <cstdio>
#include <algorithm>

typedef long long LL;

int n, k;
LL x;
LL a[200002];
LL ki[200002];
LL ka[200002];

int main () {
    scanf("%d %d %I64d", &n, &k, &x);

    LL mul = 1;
    while (k--) mul *= x;

    for (int i=0; i<n; i++) scanf("%I64d", &a[i]), ki[i] = ki[i-1] | a[i];
    for (int i=n-1; i>=0; i--) ka[i] = ka[i+1] | a[i];

    LL maks = 0;
    for (int i=0; i<n; i++) maks = std::max(maks, ki[i-1] | (a[i] * mul) | ka[i+1]);

    printf("%I64d\n", maks);

    return 0;
}