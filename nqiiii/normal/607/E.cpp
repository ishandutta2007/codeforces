#include <bits/stdc++.h>
using namespace std;
typedef long long Long;
const int maxN = 50000;
int n, m, c[maxN * 2 + 10], cnt;
double k[maxN + 10], b[maxN + 10], x, y;
struct Seg {
    double l, r;
    int idL, idR, frm;
    bool operator < (const Seg &t) const {
        return idR < t.idR;
    }
}a[maxN + 10];
int aCnt;
double ans, maxV;
struct Num {
    int pos, id;
    double val;
    bool operator < (const Num &t) const {
        return val < t.val;
    }
}s[maxN * 2 + 10];

void Add(int p, int v) {
    for (; p <= aCnt * 2; p += p & -p) c[p] += v;
}

int Query(int p) {
    int ans = 0;
    for (; p; p -= p & -p) ans += c[p];
    return ans;
}

vector<int> v[maxN * 8 + 10];

void GetAns(int p, int q) {
    double xx = (b[q] - b[p]) / (k[p] - k[q]);
    double yy = k[p] * xx + b[p];
    double now = sqrt((xx - x) * (xx - x) + (yy - y) * (yy - y));
    ans += now; ++cnt;
    if (cnt == m) {
        printf("%.10lf", ans); exit(0);
    }
}

void Query(int p, int k, int id, int ls, int rs) {
    for (int i = 0; i < v[p].size(); ++i) {
        int e = v[p][i];
        GetAns(e, id);
    }
    if (ls != rs) {
        int mid = (ls + rs) / 2;
        if (k <= mid) Query(p * 2, k, id, ls, mid);
        else Query(p * 2 + 1, k, id, mid + 1, rs);
    }
}

void Add(int p, int l, int r, int id, int ls, int rs) {
    if (l == ls && r == rs) v[p].push_back(id);
    else {
        int mid = (ls + rs) / 2;
        if (r <= mid) Add(p * 2, l, r, id, ls, mid);
        else if (l > mid) Add(p * 2 + 1, l, r, id, mid + 1, rs);
        else {
            Add(p * 2, l, mid, id, ls, mid);
            Add(p * 2 + 1, mid + 1, r, id, mid + 1, rs);
        }
    }
}

Long Check(double d) {
    aCnt = 0;
    for (int i = 1; i <= n; ++i) {
        double fir = k[i] * k[i] + 1,
               sec = 2 * k[i] * b[i] - 2 * k[i] * y - 2 * x,
               thi = 1ll * x * x + 1ll * y * y + b[i] * b[i] - 2 * b[i] * y - d * d;
        double delta = sec * sec - 4 * fir * thi;
        if (delta >= 0) {
            delta = sqrt(delta);
            double xA = (-sec + delta) / (2 * fir),
                   xB = (-sec - delta) / (2 * fir);
            a[++aCnt].l = atan2(k[i] * xA + b[i] - y, xA - x);
            a[aCnt].r = atan2(k[i] * xB + b[i] - y, xB - x);
            if (a[aCnt].l > a[aCnt].r) swap(a[aCnt].l, a[aCnt].r);
            a[aCnt].frm = i;
        }
    }
    for (int i = 1; i <= aCnt; ++i) {
        s[i * 2 - 1] = (Num){i, 0, a[i].l};
        s[i * 2] = (Num){i, 1, a[i].r};
    }
    sort(s + 1, s + aCnt * 2 + 1);
    for (int i = 1; i <= aCnt * 2; ++i)
        if (s[i].id == 0) a[s[i].pos].idL = i;
        else a[s[i].pos].idR = i;
    sort(a + 1, a + aCnt + 1);
    for (int i = 1; i <= aCnt * 2; ++i) c[i] = 0;
    Long ans = 0;
    for (int i = 1; i <= aCnt; ++i) {
        ans += Query(a[i].idL);
        Add(a[i].idL, 1); Add(a[i].idR + 1, -1);
    }
    return ans;
}

int main() {
    scanf("%d", &n);
    scanf("%lf%lf%d", &x, &y, &m);
    x /= 1000; y /= 1000;
    for (int i = 1; i <= n; ++i) {
        scanf("%lf%lf", &k[i], &b[i]);
        k[i] /= 1000; b[i] /= 1000;
    }
    double l = 0, r = 1e15;
    while (r - l > max(l, 1.0) * (1e-8)) {
        double mid = (l + r) / 2;
        if (Check(mid) < m) l = mid; else r = mid;
    }
    Long now = Check(r);
    for (int i = 1; i <= aCnt; ++i) {
        Query(1, a[i].idL, a[i].frm, 1, aCnt * 2);
        Add(1, a[i].idL, a[i].idR, a[i].frm, 1, aCnt * 2);
    }
    printf("%.10lf", ans - maxV * (cnt - m));
}