
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 200005, INF = 0x3f3f3f3f;
struct Pt {
    ll x, y;
    Pt() {}
    Pt(int xx, int yy) {
        x = xx;
        y = yy;
    }
    Pt operator+(const Pt &o) { return Pt(x + o.x, y + o.y); }
    Pt operator-(const Pt &o) { return Pt(x - o.x, y - o.y); }
    ll operator*(const Pt &o) { return x * o.x + y * o.y; }
    ll operator^(const Pt &o) { return x * o.y - y * o.x; }
} A[MAXN], B[MAXN], st[MAXN];
 
bool cmp(Pt a, Pt b) {
    ll t = a ^ b;
    return t == 0 ? a * a < b * b : t > 0;
}
 
int n, m;
ll sa[MAXN], sb[MAXN];
 
int hull(int n, Pt *P, ll res[]) {
    Pt O(INF, INF);
    for (int i = 0; i < n; ++i) {
        if (P[i].x < O.x || P[i].x == O.x && P[i].y < O.y) O = P[i];
    }
    for (int i = 0; i < n; ++i) P[i] = P[i] - O;
    sort(P, P + n, cmp);
    int top = 0;
    st[top++] = P[0];
    st[top++] = P[1];
    // printf("%I64d, %I64d\n", P[0].x, P[0].y);
    // printf("%I64d, %I64d\n", P[1].x, P[1].y);
    for (int i = 2; i < n; ++i) {
        // printf("%I64d, %I64d\n", P[i].x, P[i].y);
        while (top >= 2 &&
               ((st[top - 1] - st[top - 2]) ^ (P[i] - st[top - 1])) <= 0)
            top--;
        st[top++] = P[i];
    }
    int cnt = 0;
    for (int i = 0; i < top; ++i) {
        int j = (i + 1) % top, k = (i + 2) % top;
        res[cnt++] = (st[j] - st[i]) * (st[j] - st[i]);
        res[cnt++] = (st[j] - st[i]) * (st[k] - st[j]);
    }
    return cnt;
}
 
int repr(ll a[]) {
    int i = 0, j = 1, k = 0;
    while (i < n && j < n && k < n) {
        ll t = a[(i + k) % n] - a[(j + k) % n];
        if (!t)
            k++;
        else {
            (t > 0 ? i : j) += k + 1;
            if (i == j) ++j;
            k = 0;
        }
    }
    return min(i, j);
}
 
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        A[i] = Pt(x, y);
    }
    for (int i = 0; i < m; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        B[i] = Pt(x, y);
    }
    n = hull(n, A, sa);
    m = hull(m, B, sb);
    if (n != m) {
        puts("NO");
        return 0;
    }
    int ia = repr(sa), ib = repr(sb);
    for (int i = 0; i < n; ++i) {
        if (sa[(ia + i) % n] != sb[(ib + i) % n]) {
            puts("NO");
            return 0;
        }
    }
    puts("YES");
}