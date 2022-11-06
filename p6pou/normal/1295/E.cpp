#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

const int MAX_N = 200000 + 5;
const int MAX_SEG = 1 << 19 | 5;

int N, p[MAX_N], a[MAX_N], pos[MAX_N];
i64 f0[MAX_N], ans;

struct SegmentNode {
    i64 min, lazy;
};
SegmentNode node[MAX_SEG];

inline void segment_update(int i) {
    node[i].min = min(node[i << 1].min, node[i << 1 | 1].min);
}

inline void segment_pushdown(int i) {
    i64 lz = node[i].lazy;
    node[i].lazy = 0;
    node[i << 1].min += lz;
    node[i << 1].lazy += lz;
    node[i << 1 | 1].min += lz;
    node[i << 1 | 1].lazy += lz;
}

void segment_build(int i, int l, int r) {
    node[i].lazy = 0;
    if (l == r) {
        node[i].min = f0[l];
    } else {
        int mid = l + r >> 1;
        segment_build(i << 1, l, mid);
        segment_build(i << 1 | 1, mid + 1, r);
        segment_update(i);
    }
}

void segment_add(int i, int l, int r, int al, int ar, int av) {
    if (al <= l && r <= ar) {
        node[i].min += av;
        node[i].lazy += av;
        return;
    }
    if (node[i].lazy) {
        segment_pushdown(i);
    }
    int mid = l + r >> 1;
    if (al <= mid) {
        segment_add(i << 1, l, mid, al, ar, av);
    }
    if (mid + 1 <= ar) {
        segment_add(i << 1 | 1, mid + 1, r, al, ar, av);
    }
    segment_update(i);
}

void segment_print(int i, int l, int r) {
    if (l == r) {
        printf("%lld,", node[i].min);
        return;
    }
    if (node[i].lazy) {
        segment_pushdown(i);
    }
    int mid = l + r >> 1;
    segment_print(i << 1, l, mid);
    segment_print(i << 1 | 1, mid + 1, r);
}

int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i ++) {
        scanf("%d", &p[i]);
        pos[p[i]] = i;
    }
    for (int i = 1; i <= N; i ++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= N; i ++) {
        f0[i] = f0[i - 1] + a[pos[i]];
    }
    ans = min(a[1], a[N]);
    segment_build(1, 0, N);
        // segment_print(1, 0, N);
        // printf("\n");
    for (int k = 1; k < N; k ++) {
        segment_add(1, 0, N, p[k], N, -a[k]);
        segment_add(1, 0, N, 0, p[k] - 1, a[k]);

        // printf("k=%d :: ", k);
        // segment_print(1, 0, N);
        // printf("\n");

        ans = min(ans, node[1].min);
    }
    printf("%lld\n", ans);
    return 0;
}