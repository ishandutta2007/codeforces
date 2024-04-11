#include<bits/stdc++.h>
using namespace std;
#define MAXN 200000

struct ST{
    int isi[4 * MAXN + 2];
    int lazy[4 * MAXN + 2];

    void propagate (int node) {
        if (lazy[node] == -1) return;
        for (int i=0; i<2; i++) {
            isi[2 * node + i] = lazy[node];
            lazy[2 * node + i] = lazy[node];
        }
        lazy[node] = -1;
        return;
    }

    void update (int node, int l, int r, int a, int b, int val) {
        if (l > b || r < a) return;
        if (l >= a && r <= b) {
            isi[node] = val;
            lazy[node] = val;
            return;
        }

        propagate(node);

        int mid = (l + r) >> 1;
        update (2*node+0, l, mid+0, a, b, val);
        update (2*node+1, mid+1, r, a, b, val);
        return;
    }

    int query (int node, int l, int r, int x) {
        if (l > x || r < x) return 0;
        if (l == x && r == x) return isi[node];

        propagate(node);

        int mid = (l + r) >> 1;
        return query(2*node, l, mid, x) + query(2*node+1, mid+1, r, x);
    }
};

int n, k, a;
int m;
ST kiri, kanan;

int main() {
    scanf("%d %d %d", &n, &k, &a);
    scanf("%d", &m);

    int now = (n + 1) / (a + 1);
    int x;
    kiri.update(1, 1, n, 1, n, 1);
    kanan.update(1, 1, n, 1, n, n);
    for (int i=0; i<m; i++) {
        scanf("%d", &x);
        int l = kiri.query(1, 1, n, x);
        int r = kanan.query(1, 1, n, x);

        now -= (r - l + 2) / (a + 1);
        now += (x - l + 1) / (a + 1);
        now += (r - x + 1) / (a + 1);

        if (now < k) {
            printf("%d\n", i+1);
            return 0;
        }

        kiri.update(1, 1, n, x+1, r, x+1);
        kanan.update(1, 1, n, l, x-1, x-1);
    }

    puts("-1");
    return 0;
}