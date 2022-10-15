#include <cstdio>

template<typename t>
t next() {
    int c = getchar();
    while (c != '-' && (c < '0' || c > '9')) c = getchar();
    int sg = 0;
    if (c == '-') {
        c = getchar();
        sg = 1;
    }
    t ret = 0;
    while (c >= '0' && c <= '9') {
        ret = ret * 10 + c - '0';
        c = getchar();
    }
    return ret;
}

int main() {
    int a = next<int>();
    int b = next<int>();
    int n = next<int>();
    int aa = a;
    a %= b;
    int d0 = -1;
    for (int i = 0; i < 10; i++) {
        if ((a * 10 + i) % b == 0) {
            d0 = i;
        }
    }
    if (d0 < 0) {
        puts("-1");
        return 0;
    }
    printf("%d", aa);
    putchar('0' + d0);
    for (int i = 0; i + 1 < n; i++) putchar('0');
    puts("");
}