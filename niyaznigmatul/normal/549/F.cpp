#include <bits/stdc++.h>

using namespace std;

int const T = 1 << 20;

int mx[2 * T];


int const N = 777777;
#define right rightasdhjlkasdjlk
#define left leftajsdlkjskldj

vector<int> ms[T];
int b[N];
int cright[N], cleft[N], left[N], right[N], q[N], a[N], wh[N];

void setIt(int v, int y) {
    v += T;
    mx[v] = y;
    while (v > 1) {
        v >>= 1;
        if (a[mx[v + v]] > a[mx[v + v + 1]])
            mx[v] = mx[v + v];
        else
            mx[v] = mx[v + v + 1];
    }
}

int getmax(int l, int r) {
    --r;
    l += T;
    r += T;
    int ret = -1;
    while (l <= r) {
        if ((l & 1) == 1) {
            if (ret < 0 || a[mx[l]] > a[ret]) ret = mx[l];
            ++l;
        }
        if ((r & 1) == 0) {
            if (ret < 0 || a[mx[r]] > a[ret]) ret = mx[r];
            --r;
        }
        l >>= 1;
        r >>= 1;
    }
    return ret;
}

int getint() {
    int c = getchar();
    while (c <= 32) c = getchar();
    int x = 0;
    while (c > 32) {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x;
}

int main() {
    int n, k;
//    scanf("%d%d", &n, &k);
    n = getint();
    k = getint();
//    for (int i = 0; i < n; i++) scanf("%d", a + i);
    for (int i = 0; i < n; i++) a[i] = getint();
    b[0] = 0;
    for (int i = 1; i <= n; i++) {
        b[i] = (b[i - 1] + a[i - 1]) % k;
    }
    for (int i = 0; i < n; i++) {
        setIt(i, i);
    }
    int vn = 0;
    int head = 0;
    int tail = 0;
    q[tail++] = vn++;
    left[0] = 0;
    right[0] = n;
    while (head < tail) {
        int v = q[head++];
        wh[v] = getmax(left[v], right[v]);
        if (left[v] < wh[v]) {
            left[vn] = left[v];
            right[vn] = wh[v];
            q[tail++] = vn++;
        }
        if (wh[v] + 1 < right[v]) {
            left[vn] = wh[v] + 1;
            right[vn] = right[v];
            q[tail++] = vn++;
        }
    }
    long long ans = 0;
    for (int i = 0; i <= n; i++) ms[b[i]].push_back(i);
    for (int i = vn - 1; i >= 0; i--) {
        int v = q[i];
        int cval = a[wh[v]] % k;
        if (wh[v] - left[v] > right[v] - wh[v]) {
            for (int i = wh[v] + 1; i <= right[v]; i++) {
                int val = (b[i] + k - cval) % k;
                ans += upper_bound(ms[val].begin(), ms[val].end(), wh[v]) - lower_bound(ms[val].begin(), ms[val].end(), left[v]);
            }
        } else {
            for (int i = left[v]; i <= wh[v]; i++) {
                int val = (b[i] + cval) % k;
                ans += upper_bound(ms[val].begin(), ms[val].end(), right[v]) - lower_bound(ms[val].begin(), ms[val].end(), wh[v] + 1);
            }
        }
    }
    printf("%I64d\n", ans - n);
}