
#include <cstdio>

int ni() {
    int c = getchar();
    while (c != '-' && (c < '0' || c > '9')) c = getchar();
    int sg = 0;
    if (c == '-') {
        c = getchar();
        sg = 1;
    }
    int ret = 0;
    while (c >= '0' && c <= '9') {
        ret = ret * 10 + c - '0';
        c = getchar();
    }
    return sg ? -ret : ret;

}

int p[123456], dp[123456];
int a[555][555];

int main() {
    p[0] = p[1] = 1;
    for (int i = 2; i * i < 123456; i++) {
        if (!p[i]) {
            for (int j = i * i; j < 123456; j += i) {
                p[j] = 1;
            }
        }
    }
    for (int i = 123450; i >= 0; i--) {
        if (!p[i]) dp[i] = 0; else dp[i] = dp[i + 1] + 1;
    }
    int n = ni();
    int m = ni();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            a[i][j] = dp[ni()];
        }
    }
    int ans = 1 << 30;
    for (int i = 0; i< n; i++) {
        int s = 0;
        for (int j = 0; j < m; j++) s += a[i][j];
        if (s < ans) ans = s;
    }
    for (int i = 0; i < m; i++){
        int s = 0;
        for (int j = 0; j<n;j++) s += a[j][i];
        if (s < ans) ans = s;
    }
    printf("%d\n", ans);
}