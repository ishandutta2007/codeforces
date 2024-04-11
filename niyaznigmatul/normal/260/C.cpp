#include <cassert>
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
    return ret;

}

long long a[123456];
int n;

void pr() {
    for (int i = 0; i < n; i++) {
        if (i > 0) putchar(' ');
        printf("%I64d", a[i]);
    }
    puts("");
}

int main() {
    n = ni();
    int x = ni() - 1;
    long long sum = 0;
    int mi = 1 << 30;
    for (int i = 0; i < n; i++) a[i] = ni();
    for (int i = 0; i < n; i++) {
        sum += a[i];
        if (mi > a[i]) mi = a[i];
    }
    for (int i = 0; i < n; i++) {
        int laps = a[i];
        if (laps != mi) continue;
        int bad = 0;
        if (i == x) {
            for (int j = 0; j < n; j++) a[j] -= laps;
            a[i] = 1LL * laps * n;
            pr();
            return 0;
        }
        for (int j = (i + 1) % n; ; ) {
            if (a[j] == mi) {
                bad = 1;
                break;
            }
            if (j == x) break;
            ++j;
            if (n == j) j = 0;
        }
        if (bad) continue;
        long long s = 0;
        for (int j = (i + 1) % n; ; ) {
            a[j] -= laps + 1;
            s += laps + 1;
            if (j == x) break;
            ++j;
            if (n == j) j = 0;
        }
        for (int j = (x + 1) % n; j != i; ) {
            a[j] -= laps;
            s += laps;
            ++j;
            if (n == j) j = 0;
        }
        a[i] += s;
        pr();
        return 0;
    }
    assert(false);
}