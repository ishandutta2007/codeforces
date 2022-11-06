#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 2000 + 5;

int N;
struct Point {
    int x, y, k, v;
} a[MAX_N];
int vis[MAX_N], pos[MAX_N];
int K, op[MAX_N << 1];

inline bool cmp_by_kv(const Point &a, const Point &b) {
    return abs(a.k - a.v) > abs(b.k - b.v);
}
inline bool cmp_by_xy(const Point &a, const Point &b) {
    return a.x < b.x || a.x == b.x && a.y < b.y;
}
inline bool cmp_by_arg(const Point &a, const Point &b) {
    return 1ll * a.x * b.y - 1ll * a.y * b.x > 0;
}

int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i ++) {
        scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].v);
        a[i].k = i;
    }
    sort(a + 1, a + 1 + N, cmp_by_kv);
    for (; N >= 1 && a[N].k == a[N].v; N --);
    if (N == 0) {
        printf("0\n");
        return 0;
    }
    sort(a + 1, a + 1 + N, cmp_by_xy);
    for (int i = N; i >= 1; i --) {
        a[i].x -= a[1].x, a[i].y -= a[1].y;
    }
    sort(a + 2, a + 1 + N, cmp_by_arg);
    for (int i = 1; i <= N; i ++) {
        pos[a[i].k] = i;
    }
    // printf("N=%d\n", N);
    while (true) {
        int cnt = 0;
        for (int i = 1; ; i = pos[a[i].v]) {
            vis[i] = 1, cnt ++;
            if (pos[a[i].v] == 1) break;
        }
        // for (int i = 1; i <= N; i ++) {
        //     printf("i=%d,k=%d,v=%d vis=%d\n", i, a[i].k, a[i].v, vis[i]);
        // }
        // printf("cnt=%d\n", cnt);
        if (cnt == N) break;
        for (int i = 2; i < N; i ++) {
            if (vis[i] == vis[i + 1]) continue;
            op[++ K] = a[i].k << 12 | a[i + 1].k;
            swap(a[i].v, a[i + 1].v);
            cnt = 0;
            break;
        }
    }
    // printf("N=%d\n", N);
    while (a[1].k != a[1].v) {
        int j = pos[a[1].v];
        op[++ K] = a[1].k << 12 | a[j].k;
        swap(a[1].v, a[j].v);
    }
    printf("%d\n", K);
    for (int i = 1; i <= K; i ++) {
        printf("%d %d\n", op[i] >> 12, op[i] & 0xfff);
    }
    return 0;
}