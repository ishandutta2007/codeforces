#include <bits/stdc++.h>

using namespace std;

int const N = 1234567;

int s[N], t[N];

int z[42][42];

int main() {
    int n;
    scanf("%d", &n);
    int c = getchar();
    while (c <= 32) c = getchar();
    for (int i = 0; i < n; i++) s[i] = c, c = getchar();
    while (c <= 32) c = getchar();
    for (int i = 0; i < n; i++) t[i] = c, c = getchar();
    memset(z, -1, sizeof z);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        z[s[i] - 'a'][t[i] - 'a'] = i;
        if (s[i] != t[i]) ++ans;
    }
    for (int a = 0; a < 26; a++)
        for (int b = 0; b < 26; b++)
            if (a != b && z[a][b] >= 0 && z[b][a] >= 0) {
                printf("%d\n", ans - 2);
                printf("%d %d\n", z[a][b] + 1, z[b][a] + 1);
                return 0;
            }
    for (int a = 0; a < 26; a++) {
        for (int b = 0; b < 26; b++) {
            if (a == b) continue;
            for (int d = 0; d < 26; d++) {
                if (d == a) continue;
                if (z[a][b] >= 0 && z[d][a] >= 0) {
                    printf("%d\n", ans - 1);
                    printf("%d %d\n", z[a][b] + 1, z[d][a] + 1);
                    return 0;
                }
            }
        }
    }
    printf("%d\n-1 -1\n", ans);
}