#include <cstdio>
#include <algorithm>

using namespace std;
const int N = 2e5;

long long cnt[N], f[N];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        cnt[x]++;
    }
    for (int i = 1; i < N; i++) f[i] = max(f[max(i - 2, 0)] + cnt[i] * i, f[i - 1]);
    printf("%I64d\n", f[N - 1]);
    return 0;
}