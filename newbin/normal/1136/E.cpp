#include <bits/stdc++.h>
#define ls(x) (x << 1)
#define rs(x) ((x << 1) | 1)
#define LL long long
using namespace std;
const int maxn = 100010;
const LL INF = 1e18;
LL a[maxn], b[maxn], c[maxn];
int n, m, now;
struct SegementTree{
    LL sum, tot;
    int l, r;
};
SegementTree tr[maxn * 4];
 
LL cal(int l, int r) {
    return (c[r] - c[l]) - (r - l) * (b[l]);
}
void pushup(int x) {
    tr[x].sum = tr[ls(x)].sum + tr[rs(x)].sum;
}
 
void maintain(int x,LL tot) {
    if(tot == -INF) return;
    int l = tr[x].l, r = tr[x].r;
    tr[x].sum = (r - l + 1) * tot + (c[r] - c[l - 1]);
    tr[x].tot = tot;
}
 
void pushdown(int x) {
    maintain(ls(x), tr[x].tot);
    maintain(rs(x), tr[x].tot);
    tr[x].tot = -INF;
}
 
void build(int x, int l, int r) {
    tr[x].l = l, tr[x].r = r;
    tr[x].tot = -INF;
    if(l == r) {
        tr[x].sum = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(ls(x), l, mid);
    build(rs(x), mid + 1, r);
    pushup(x);
}
 
LL query(int x, int l, int r, int ql, int qr) {
    if(l >= ql && r <= qr) {
        return tr[x].sum;
    }
    int mid = (l + r) >> 1;
    LL ans = 0;
    pushdown(x);
    if(ql <= mid) ans += query(ls(x), l, mid, ql, qr);
    if(qr > mid) ans += query(rs(x), mid + 1, r, ql, qr);
    return ans;
}
 
void update(int x, int l, int r, int ql, int qr, LL val) {
    if(l >= ql && r <= qr) {
        maintain(x, val);
        return;
    }
    int mid = (l + r) >> 1;
    pushdown(x);
    if(mid >= ql) update(ls(x), l, mid, ql, qr, val);
    if(mid < qr) update(rs(x), mid + 1, r, ql, qr, val);
    pushup(x);
}
 
int main() {
    int x, y;
    char s[5];
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%I64d", &a[i]);
    }
    for (int i = 2; i <= n; i++) {
        scanf("%I64d", &b[i]);
        b[i] += b[i - 1];
    }
    for (int i = 2; i <= n; i++)
        c[i] = c[i - 1] + b[i];
    build(1, 1, n);
    scanf("%d", &m);
    while(m--) {
        scanf("%s%d%d", s + 1, &x, &y);
        if(s[1] == '+') {
            int l = x, r = n;
            LL tmp = query(1, 1, n, x, x);
            LL ans = x;
            while(l <= r) {
                int mid = (l + r) >> 1;
                LL tmp1 = query(1 , 1, n, mid, mid);
                if(tmp + y + b[mid] - b[x] > tmp1)
                    l = mid + 1,ans = mid;
                else r = mid - 1;
            }
            now = x;
            update(1, 1, n, x, ans, tmp + y - b[x]);
        } else {
            printf("%I64d\n", query(1, 1, n, x, y));
        }
    }
}