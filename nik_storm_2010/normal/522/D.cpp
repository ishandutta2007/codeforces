#include <cstdio>
#include <map>
#include <vector>

using namespace std;
const int N = 5e5 + 10;
const int INF = 2e9;

int a[N], b[N], c[N], res, l, r;
map <int, int> base;
vector <int> val[4 * N], ps[4 * N];

void build(int i, int l, int r) {
    if (l == r) {
        ps[i].push_back(b[l]);
        val[i].push_back(c[l]);
        return;
    }
    int m = (l + r) / 2;
    build(i * 2, l, m);
    build(i * 2 + 1, m + 1, r);
    int i1 = 0, i2 = 0;
    int l1 = (int)val[i * 2].size(), l2 = (int)val[i * 2 + 1].size();
    int curval = INF;
    while (i1 < l1 || i2 < l2) {
        if (i1 == l1) {
            curval = min(curval, val[i * 2 + 1][i2]);
            ps[i].push_back(ps[i * 2 + 1][i2]);
            val[i].push_back(curval);
            i2++;
        } else if (i2 == l2) {
            curval = min(curval, val[i * 2][i1]);
            ps[i].push_back(ps[i * 2][i1]);
            val[i].push_back(curval);
            i1++;
        } else if (ps[i * 2][i1] > ps[i * 2 + 1][i2]) {
            curval = min(curval, val[i * 2 + 1][i2]);
            ps[i].push_back(ps[i * 2 + 1][i2]);
            val[i].push_back(curval);
            i2++;
        } else {
            curval = min(curval, val[i * 2][i1]);
            ps[i].push_back(ps[i * 2][i1]);
            val[i].push_back(curval);
            i1++;
        }
    }
}

void query(int i, int il, int ir, int ql, int qr) {
    if (ql == il && qr == ir) {
        if (ps[i][0] > r) {
            return;
        }
        int ll = 0, rr = (int)ps[i].size();
        while (rr - ll > 1) {
            int mm = (ll + rr) / 2;
            if (ps[i][mm] <= r) {
                ll = mm;
            } else {
                rr = mm;
            }
        }
        res = min(res, val[i][ll]);
        return;
    }
    int m = (il + ir) / 2;
    if (ql <= m) {
        query(i * 2, il, m, ql, min(qr, m));
    }
    if (m < qr) {
        query(i * 2 + 1, m + 1, ir, max(ql, m + 1), qr);
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = n; i >= 1; i--) {
        b[i] = base[a[i]];
        if (b[i] == 0) {
            b[i] = INF;
        }
        c[i] = b[i] - i;
        base[a[i]] = i;
    }
    build(1, 1, n);
    for (int q = 1; q <= m; q++) {
        scanf("%d %d", &l, &r);
        res = INF;
        query(1, 1, n, l, r);
        if (res == INF) {
            res = -1;
        }
        printf("%d\n", res);
    }
    return 0;
}