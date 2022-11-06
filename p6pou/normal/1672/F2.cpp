#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 200000 + 5;

int T, N, S, ans;
int a[MAX_N], b[MAX_N], cnt[MAX_N], ins[MAX_N];
int elast[MAX_N], ey[MAX_N], enext[MAX_N];

void dfs(int u) {
    cnt[u] = 0, ins[u] = 1;
    for (int j = elast[u]; j; j = enext[j]) {
        int v = ey[j];
        if (ins[v]) ans = 0;
        if (cnt[v]) dfs(v);
    }
    ins[u] = 0, elast[u] = 0;
}

int main() {
    for (scanf("%d", &T); T --; ) {
        scanf("%d", &N);
        for (int i = 1; i <= N; i ++) {
            scanf("%d", &a[i]);
            cnt[a[i]] ++;
        }
        S = 0;
        for (int i = 1; i <= N; i ++) {
            scanf("%d", &b[i]);
            S = cnt[S] < cnt[b[i]] ? b[i] : S;
        }
        
        // printf("S=%d\n", S);
        for (int i = 1; i <= N; i ++) {
            if (a[i] == S || b[i] == S) continue;
            // printf("%d->%d\n", a[i], b[i]);
            ey[i] = b[i];
            enext[i] = elast[a[i]];
            elast[a[i]] = i;
        }
        ans = 1;
        for (int i = 1; i <= N; i ++) {
            if (cnt[i]) dfs(i);
        }
        printf(ans ? "AC\n" : "WA\n");
    }
    return 0;
}