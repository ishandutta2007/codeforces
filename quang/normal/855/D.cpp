#include <bits/stdc++.h>

using namespace std;

const int N = 100010, LOG = 20;

int n;
vector<int> a[N];
int color[N];
int in[N], out[N], cnt;
int sum[2][N * 2];
int pa[LOG][N], lv[N];
int belong[N];

void dfs(int u, int p) {
    belong[u] = p;
    in[u] = ++cnt;
    sum[0][in[u]] = (color[u] == 0);
    sum[1][in[u]] = (color[u] == 1);
    for (int v : a[u]) {
        pa[0][v] = u;
        lv[v] = lv[u] + 1;
        for (int i = 1; i < LOG; i++) {
            pa[i][v] = pa[i - 1][pa[i - 1][v]];
        }
        dfs(v, p);
    }
    out[u] = ++cnt;
    sum[0][out[u]] = -(color[u] == 0);
    sum[1][out[u]] = -(color[u] == 1);
}

bool checkPar(int u, int v) {
    return in[u] <= in[v] && out[v] <= out[u];
}

bool get1(int u, int v) {
    if (belong[u] != belong[v]) {
        return 0;
    }
    if (u == v) {
        return 1;
    }
    if (!checkPar(u, v)) {
        return 0;
    }
    int tot = sum[0][in[v]] - sum[0][in[u]];
    return tot == lv[v] - lv[u];
}

int lca(int u, int v) {
    if (lv[u] > lv[v]) {
        swap(u, v);
    }
    int h = lv[v] - lv[u];
    for (int i = LOG - 1; i >= 0; i--) {
        if (h & (1 << i)) {
            v = pa[i][v];
        }
    }
    if (u == v) {
        return u;
    }
    for (int i = LOG - 1; i >= 0; i--) {
        if (pa[i][u] != pa[i][v]) {
            u = pa[i][u];
            v = pa[i][v];
        }
    }
    return pa[0][u];
}

bool get2(int u, int v) {
    if (belong[u] != belong[v]) {
        return 0;
    }
//    cout << "go to get2 " << u << " " << v << endl;
    if (u == v) {
        return 0;
    }
    if (checkPar(u, v)) {
        int tot = sum[1][in[v]] - sum[1][in[u]];
//        cout << "sum " <<  sum[1][in[v]] << " " << sum[1][in[u]] << endl;
        return tot == lv[v] - lv[u];
    }
    int w = lca(u, v);
    return get2(w, v) && get1(w, u);
}

int main() {
    scanf("%d", &n);
    vector<int> start;
    for (int i = 1; i <= n; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        if (u == -1) {
            start.push_back(i);
            continue;
        }
        a[u].push_back(i);
        color[i] = v;
    }
    for (int u : start) {
        dfs(u, u);
    }
    for (int i = 1; i <= n * 2; i++) {
        sum[0][i] += sum[0][i - 1];
        sum[1][i] += sum[1][i - 1];
    }
    int q;
    scanf("%d", &q);
//    get2(1, 2);
//    return 0;
    while (q--) {
        int type, u, v;
        scanf("%d %d %d", &type, &u, &v);
        if (u == v) {
            puts("NO");
            continue;
        }
        if (type == 1) {
            if (get1(u, v)) {
                puts("YES");
            } else {
                puts("NO");
            }
        } else {
            if (get2(u, v)) {
                puts("YES");
            } else {
                puts("NO");
            }
        }
    }
    return 0;
}