#include <cstdio>

int ni() {
    int c = getchar();
    while (c != '-' && (c < '0' || c > '9')) c = getchar();
    int sg = 0;
    if (c == '-') {
        sg = 1;
        c = getchar();
    }   
    int ret = 0;
    while (c >= '0' && c <= '9') {
        ret = ret * 10 + c - '0';
        c = getchar();
    }
    return sg ? -ret : ret;
}

int p[123456];

int main() {
    int n = ni();
    int k = ni();
    for (int i = 0; i < n; i++) p[i] = i;
    for (int i = n - k - 1, j = n - 1; i < j; i++, j--) {
        int t = p[i];
        p[i] = p[j];
        p[j] = t;
    } 
    for (int i = 0; i < n; i++) {
        if (i > 0) putchar(' ');
        printf("%d", p[i] + 1);
    }
    puts("");
}