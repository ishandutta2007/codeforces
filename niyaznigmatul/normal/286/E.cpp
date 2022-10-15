#include <cassert>
#include <memory.h>
#include <cstdio>
#include <cmath>
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

const double PI = M_PI;

    int revv(int x, int bits) {
        int ret = 0;
        for (int i = 0; i < bits; i++) {
            ret <<= 1;
            ret |= x & 1;
            x >>= 1;
        }
        return ret;
    }


    void fft(double * a, double * b, int n, bool rev) {
        int bits = 0;
        while (1 << bits < n) ++bits;
        for (int i = 0; i < n; i++) {
            int j = revv(i, bits);
            if (i < j) {
                double t = a[i];
                a[i] = a[j];
                a[j] = t;
                t = b[i];
                b[i] = b[j];
                b[j] = t;
            }
        }
        for (int len = 2; len <= n; len <<= 1) {
            int half = len >> 1;
            double wmx = cos(2 * PI / len);
            double wmy = sin(2 * PI / len);
            if (rev)
                wmy = -wmy;
            for (int i = 0; i < n; i += len) {
                double wx = 1;
                double wy = 0;
                for (int j = 0; j < half; j++) {
                    double cx = a[i + j];
                    double cy = b[i + j];
                    double dx = a[i + j + half];
                    double dy = b[i + j + half];
                    double ex = dx * wx - dy * wy;
                    double ey = dx * wy + dy * wx;
                    a[i + j] = cx + ex;
                    b[i + j] = cy + ey;
                    a[i + j + half] = cx - ex;
                    b[i + j + half] = cy - ey;
                    double wnx = wx * wmx - wy * wmy;
                    double wny = wx * wmy + wy * wmx;
                    wx = wnx;
                    wy = wny;
                }
            }
        }
        if (rev) {
            for (int i = 0; i < n; i++) {
                a[i] /= n;
                b[i] /= n;
            }
        }
    }
    
const int N = 1 << 21;

double ax[N], ay[N];
int cnt[N];

int main() {
    int n = ni();
    int m = ni();
    memset(ax, 0, sizeof ax);
    memset(ay, 0, sizeof ay);
    memset(cnt, 0, sizeof cnt);
    ax[0] = 1;
    for (int i = 0; i < n; i++) {
        int x = ni();
        ax[x] = 1;
        cnt[x] = 1;
    }    
    fft(ax, ay, N, false);
    for (int i = 0; i < N; i++) {
        double cx = ax[i] * ax[i] - ay[i] * ay[i];
        double cy = 2 * ax[i] * ay[i];
        ax[i] = cx;
        ay[i] = cy;
    }
    fft(ax, ay, N, true);
    for (int i = 1; i <= m; i++) {
        if (ax[i] > 0.6 && !cnt[i]) {
            puts("NO");
            return 0;
        }
    }
    int cn = 0;
    for (int i = 1; i <= m; i++) {
        if (ax[i] > 2.6) continue;
        if (ax[i] > 0.6) cn++;
    }
    puts("YES");
    printf("%d\n", cn);
    int first = 1;
    for (int i = 1; i <= m; i++) {
        if (ax[i] > 2.6) continue;        
        if (ax[i] > 0.6) {
            if (!first) putchar(' ');
            first = 0;
            printf("%d", i);
        }
    }
    puts("");
}