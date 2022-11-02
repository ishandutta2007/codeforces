#include <cstdio>

using namespace std;
const int N = 1e5 + 10;
const int MOD = 1e9 + 7;

int f[N];

int main() {
    int t, k;
    scanf("%d %d", &t, &k);
    f[0] = 1;
    for (int i = 0; i < N - 1; i++) {
        f[i + 1] += f[i];
        if (f[i + 1] >= MOD) f[i + 1] -= MOD;
        if (i + k < N) {
            f[i + k] += f[i];
            if (f[i + k] >= MOD) f[i + k] -= MOD;
        }
        f[i] += f[i - 1];
        if (f[i] >= MOD) f[i] -= MOD;
    }
    for (int i = 1; i <= t; i++) {
        int l, r;
        scanf("%d %d", &l, &r);
        int ans = f[r] - f[l - 1];
        if (ans < 0) ans += MOD;
        printf("%d\n", ans);
    }
    return 0;
}