#include <cstdio>

using namespace std;
const int MOD = 1e9 + 7;
const int N = 2e5 + 10;

int f[N], go[N];

int main() {
    int r, g;
    scanf("%d %d", &r, &g);
    f[0] = 1;
    for (int level = 1; ; level++) {
        for (int i = 0; i <= r; i++) go[i] = 0;
        int sum = level * (level - 1) / 2;
        for (int i = 0; i <= r; i++) if (f[i] != 0) {
            int left_r = r - i;
            int left_g = g - sum + i;
            if (left_r >= level) {
                go[i + level] += f[i];
                if (go[i + level] >= MOD) go[i + level] -= MOD;
            }
            if (left_g >= level) {
                go[i] += f[i];
                if (go[i] >= MOD) go[i] -= MOD;
            }
        }
        bool ok = false;
        for (int i = 0; i <= r; i++) if (go[i] > 0) ok = true;
        if (!ok) {
            int ans = 0;
            for (int i = 0; i <= r; i++) {
                ans += f[i];
                if (ans >= MOD) ans -= MOD;
            }
            printf("%d\n", ans);
            break;
        }
        for (int i = 0; i <= r; i++) f[i] = go[i];
    }
    return 0;
}