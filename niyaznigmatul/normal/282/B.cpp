#include <cstdio>

char ans[1234567];

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

int main() {
    int n = ni();
    int s = 0;
    for (int i = 0; i < n; i++) {
        int a = ni();
        ni();
        s += a;
        ans[i] = 'A';
    }
    int i = n - 1;
    while (s > 500) {
        s -= 1000;
        ans[i] = 'G';
        --i;
    }
    ans[n] = 0;
    puts(ans);
}