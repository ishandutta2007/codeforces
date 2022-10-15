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

int ans[1234567];

int main() {
    int n = ni();
    int k = ni();
    if (n / k < 3) {
        puts("-1");
        return 0;
    }
    int cur = 1;
    if ((k & 1) == 1) {
        ans[1] = k;
        cur = 2;
    }
    for (int i = 1; i + 1 <= k; i += 2) {
        ans[cur] = i;
        ans[cur + 1] = i;
        ans[cur + 2] = i + 1;
        ans[cur + 3] = i;
        ans[cur + 4] = i + 1;
        ans[cur + 5] = i + 1;
        cur += 6;
    }
    if ((k & 1) == 1) {
        ans[cur++] = k;
        ans[cur++] = k;
    }
    for (int i = 1; i <= n; i++) if (ans[i] == 0) ans[i] = 1;
    for (int i = 1; i <= n; i++) {
        if (i > 1) putchar(' ');
        printf("%d", ans[i]);
    }
    puts("");
}