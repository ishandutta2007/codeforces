#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 300000 + 5;

int N;
int a[MAX_N], pa[MAX_N];
vector<int> son[MAX_N];
int dep[MAX_N], dfn1[MAX_N], dfn2[MAX_N], dfn_;
int b[MAX_N];
long long sd = 0;

bool cmp_by_a(int i, int j) {
    return a[i] < a[j];
}
void dfs1(int u) {
    dfn1[u] = ++ dfn_;
    for (int v: son[u]) {
        dep[v] = dep[u] + 1;
        dfs1(v);
    }
}
void dfs2(int u) {
    for (int v: son[u]) {
        dfs2(v);
    }
    dfn2[u] = ++ dfn_;
}
void dfs3(int u) {
    if (b[u]) return;
    b[u] = ++ dfn_;
    for (int v: son[u]) {
        dfs3(v);
    }
}

int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i ++) {
        scanf("%d", &a[i]);
        pa[a[i]] = i;
    }
    for (int i = 1; i < N; i ++) {
        int x, y;
        scanf("%d%d", &x, &y);
        son[x].push_back(y);
    }
    for (int i = 1; i <= N; i ++) {
        sort(son[i].begin(), son[i].end(), cmp_by_a);
    }
    dfn_ = 0, dfs1(1);
    dfn_ = 0, dfs2(1);
    dfn_ = 0;
    for (int i = 1; i <= N; i ++) {
        int u = pa[i];
        if (dfn2[u] == i) {
            sd += dep[u];
            b[u] = ++ dfn_;
        } else {
            break;
        }
    }
    dfs3(1);
    // for (int i = 1; i <= N; i ++) {
    //     printf("b[%d]=%d\n", i, b[i]);
    // }
    for (int u = 1; b[u] != a[u]; ) {
        int s = 0;
        for (int v: son[u]) {
            if (b[u] < b[v]) {
                s = v;
                break;
            }
        }
        if (s == 0) {
            break;
        }
        swap(b[u], b[s]);
        u = s;
        sd ++;
    }
    for (int i = 1; i <= N; i ++) {
        if (a[i] != b[i]) {
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    printf("%lld\n", sd);
    for (int i = 1; i <= N; i ++) {
        printf("%d%c", dfn1[i], i < N ? ' ' : '\n');
    }
    return 0;
}