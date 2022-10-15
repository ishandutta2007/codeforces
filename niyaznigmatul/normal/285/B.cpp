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

int p[123456], was[123456];

int main() {
    int n = ni();
    int a = ni() - 1;
    int b = ni() - 1;
    for (int i = 0; i < n; i++) {
        p[i] = ni() - 1;
        was[i] = 0;
    }
    int cnt = 1;
    for (int i = a; !was[i]; i = p[i]) {
        was[i] = cnt;
        if (i == b) {
            break;
        }        
        ++cnt;
    }
    if (!was[b]) {
        puts("-1");
        return 0;
    }
    --cnt;
    int d = was[b] - 1;
    printf("%d\n", d);    
}