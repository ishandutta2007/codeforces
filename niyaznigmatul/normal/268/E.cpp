#include <cstdio>
#include <algorithm>

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

double a[55555];
double p[55555];
int id[55555];

bool ap(int x, int y) {
    return a[x] * p[y] > a[y] * p[x];
}

int main() {
    int n = ni();
    double ans = 0;
    for (int i = 0; i < n; i++) {
        a[i] = ni();
        ans += a[i];        
        p[i] = ni() * .01;
        a[i] *= p[i];
        p[i] = 1 - p[i];
        if (p[i] < 0) p[i] = 0;
        id[i] = i;
    }
    std::sort(id, id + n, ap);
    double cure = 0;
    for (int it = 0; it < n; it++) {
        int i = id[it];
        ans += cure * p[i];
        cure += a[i];
    }
    printf("%.17lf\n", ans);
}