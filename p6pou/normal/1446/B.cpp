#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 5000 + 5;

int A, B;
char a[MAX_N], b[MAX_N];
int ans, f[MAX_N][MAX_N];

int main() {
    scanf("%d%d", &A, &B);
    scanf("%s%s", a + 1, b + 1);
    for (int i = 1; i <= A; i ++) {
        for (int j = 1; j <= B; j ++) {
            if (a[i] == b[j]) {
                f[i][j] = f[i - 1][j - 1] + 2;
            } else {
                f[i][j] = max(f[i][j], f[i][j - 1] - 1);
                f[i][j] = max(f[i][j], f[i - 1][j] - 1);
            }
            ans = max(ans, f[i][j]);
        }
    }
    printf("%d\n", ans);
    return 0;
}