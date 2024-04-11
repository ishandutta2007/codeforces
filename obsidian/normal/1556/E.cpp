#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
#define PB push_back
#define fi first
#define se second
#define MP make_pair
const int P = 1000000007;
const int V = 100100;
struct Node {
    int l, r;
    PLL v;
}tr[4 * V];

PLL mg(PLL x, PLL y) {
    return {x.fi + y.fi, max(x.se, x.fi + y.se)};
}

void up(int id) {
    tr[id].v = mg(tr[id * 2].v, tr[id * 2 + 1].v);
}

int c[V];

void init(int id, int l, int r) {
    tr[id].l = l;
    tr[id].r = r;
    if (l == r) {
        tr[id].v = {c[l], c[l]};
        return;
    }
    int mid = (l + r) / 2;
    init(id * 2, l, mid);
    init(id * 2 + 1, mid + 1, r);
    up(id);
}

PLL read(int id, int l, int r) {
    //printf("R %d %d %d %d %d\n", id, tr[id].l, tr[id].r, l, r);
    //if (id > 100) return {0LL, 0LL};
    if (tr[id].l == l && tr[id].r == r) return tr[id].v;
    int mid = (tr[id].l + tr[id].r) / 2;
    if (r <= mid) return read(id * 2, l, r);
    else if (l > mid) return read(id * 2 + 1, l, r);
    else {
        PLL L = read(id * 2, l, mid);
        PLL R = read(id * 2 + 1, mid + 1, r);
        return mg(L, R);
    }
}

int a[V], b[V], n, Q, x, y;
int main() {
    while (~scanf("%d%d", &n, &Q)) {
        for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
        for (int i = 1; i <= n; ++i) scanf("%d", &b[i]);
        for (int i = 1; i <= n; ++i) c[i] = b[i] - a[i];
        init(1, 1, n);
        while (Q--) {
            scanf("%d%d", &x, &y);
            PLL res = read(1, x, y);
            //printf("Q %I64d %I64d\n", res.fi, res.se);
            if (res.fi != 0 || res.se < 0) puts("-1");
            else printf("%I64d\n", res.se);
        }
    }
    return 0;
}

/*
8 5
0 1 2 9 3 2 7 5
2 2 1 9 4 1 5 8
2 6
1 7
2 4
7 8
5 8
*/