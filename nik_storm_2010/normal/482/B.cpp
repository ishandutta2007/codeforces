#include <cstdio>
#include <algorithm>

using namespace std;
const int N = 1e5 + 1e3;

int tree[4 * N], push[4 * N], l[N], r[N], q[N];

void modify(int i, int l, int r, int ql, int qr, int x) {
    if (l == ql && r == qr) {
        tree[i] |= x;
        push[i] |= x;
        return;
    }
    tree[i * 2] |= push[i];
    tree[i * 2 + 1] |= push[i];
    push[i * 2] |= push[i];
    push[i * 2 + 1] |= push[i];
    push[i] = 0;
    int m = (l + r) / 2;
    if (ql <= m) modify(i * 2, l, m, ql, min(qr, m), x);
    if (m < qr) modify(i * 2 + 1, m + 1, r, max(ql, m + 1), qr, x);
    tree[i] = tree[i * 2] & tree[i * 2 + 1];
}

int get(int i, int l, int r, int ql, int qr) {
    if (l == ql && r == qr) return tree[i];
    tree[i * 2] |= push[i];
    tree[i * 2 + 1] |= push[i];
    push[i * 2] |= push[i];
    push[i * 2 + 1] |= push[i];
    push[i] = 0;
    int m = (l + r) / 2, res = (1LL << 31) - 1;
    if (ql <= m) res &= get(i * 2, l, m, ql, min(qr, m));
    if (m < qr) res &= get(i * 2 + 1, m + 1, r, max(ql, m + 1), qr);
    return res;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) scanf("%d %d %d", &l[i], &r[i], &q[i]);
    for (int i = 1; i <= m; i++) modify(1, 1, n, l[i], r[i], q[i]);
    bool ok = true;
    for (int i = 1; i <= m; i++) ok &= (q[i] == get(1, 1, n, l[i], r[i]));
    if (!ok) {
        puts("NO");
        return 0;
    }
    puts("YES");
    for (int i = 1; i <= n; i++) printf("%d ", get(1, 1, n, i, i));
    return 0;
}