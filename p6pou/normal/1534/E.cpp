#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 500 + 5;

int N, K, D;
int b[MAX_N], p[MAX_N];

bool cmp_by_b(int i, int j) {
    return b[i] > b[j];
}

int main() {
    scanf("%d%d", &N, &K);
    if ((N & 1) && (~K & 1)) {
        printf("-1\n");
        return 0;
    }
    D = (N - 1) / K + 1;
    if (K * D - N & 1) D ++;
    while (true) {
        int v = K * D / N, u = (K * D - 1) / N + 1;
        if (~v & 1) v --;
        if (~u & 1) u ++;
        if (D >= u && N * v <= K * D && N * u >= K * D && (K * D - N) % 2 == 0) break;
        D ++;
    }
    int v = K * D / N, t = K * D;
    if (~v & 1) v --;
    for (int i = N; i >= 1; i --) {
        if (t > i * v) b[i] = v + 2;
        else if (t == i * v) b[i] = v;
        else while(233);
        t -= b[i];
    }
    for (int i = 1; i <= N; i ++) {
        p[i] = i;
    }
    int ans = 0, tmp;
    for (int i = 1; i <= D && i <= 500; i ++) {
        sort(p + 1, p + 1 + N, cmp_by_b);
        printf("? ");
        for (int j = 1; j <= K; j ++) {
            if (b[p[j]] == 0) p[j] /= b[p[j]];
            b[p[j]] --;
            printf("%d%c", p[j], j < K ? ' ' : '\n');
        }
        printf("\n");
        fflush(stdout);
        scanf("%d", &tmp);
        ans ^= tmp;
    }
    printf("! %d\n", ans);
    return 0;
}