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


int p[111], q[111], a[111], b[111], pp[111], tmp[111];

void mul(int * a, int * b, int n) {
    for (int i = 0; i < n; i++) tmp[i] = a[b[i]];
    for (int i = 0; i < n; i++) a[i] = tmp[i];
}

int eq(int * a, int * b, int n) {
    for (int i = 0; i < n; i++) if (a[i] != b[i]) return 0;
    return 1;
}

int main() {
    int n = ni();
    int k = ni();
    for (int i = 0; i < n; i++) p[i] = ni() - 1;
    for (int i = 0; i < n; i++) q[i] = ni() - 1;
    for (int i = 0; i < n; i++) b[p[i]] = i;
    for (int i = 0; i < n; i++) pp[i] = b[i];
    for (int i = 0; i < n; i++) b[i] = i;
    if (eq(q, b, n)) {
        if (k == 0) puts("YES"); else puts("NO");
        return 0;
    }
    for (int r = 0; r <= k; r += 2) {
        if (r > 0 && eq(p, q, n) && eq(pp, q, n)) continue;
        for (int i = 0; i < n; i++) a[i] = i;
        int bad = 0;
        for (int j = r; j < k; j++) {
            if (eq(a, q, n)) bad = 1;
            mul(a, p, n);
        }
        if (!bad && eq(a, q, n)) {
            puts("YES");
            return 0;
        }
        bad = 0;
        for (int i = 0; i < n; i++) a[i] = i;
        for (int j = r; j < k; j++) {
            if (eq(a, q, n)) bad = 1;
            mul(a, pp, n);
        }
        if (!bad && eq(a, q, n)) {
            puts("YES");
            return 0;
        }
    }
    puts("NO");
}