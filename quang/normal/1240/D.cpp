#include <bits/stdc++.h>

using namespace std;

const int N = 300010;
const int LOG = 20;

int n;
int a[N];
int cnt;

struct Node {
    int sum, l, r;
} t[N * LOG + 4 * N];

int root[N];
int par[LOG][N];
int dp[N];

int init(int l, int r) {
    int now = cnt++;
    t[now].sum = 0;
    t[now].l = t[now].r = -1;
    if (l < r) {
        int m = l + r >> 1;
        t[now].l = init(l, m);
        t[now].r = init(m + 1, r);
    }
    return now;
}

int add(int old, int l, int r, int id) {
    int now = cnt++;
    t[now] = t[old];
    if (l == r) {
        t[now].sum++;
        return now;
    }
    int m = l + r >> 1;
    if (id <= m) t[now].l = add(t[old].l, l, m, id);
    else t[now].r = add(t[old].r, m + 1, r, id);
    return now;
}

int get(int node, int l, int r, int id) {
    if (l == r) return t[node].sum;
    int m = l + r >> 1;
    if (id <= m) return get(t[node].l, l, m, id);
    return get(t[node].r, m + 1, r, id);
}

int getFirstPos(int u, int val) {
    int foo = get(root[u], 1, n, val);
    if (!foo) return 0;

    for (int i = LOG - 1; i >= 0; i--) {
        int v = par[i][u];
        int bar = get(root[v], 1, n, val);
        if (foo == bar) u = v;
    } 
    return u;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        cin >> n;
        cnt = 0;
        dp[0] = 0;
        for (int i = 0; i < LOG; i++) {
            for (int j = 0; j <= n; j++) {
                par[i][j] = 0;
            }
        }
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        root[0] = init(1, n);
        long long res = 0;
        for (int i = 1; i <= n; i++) {
            int pos = getFirstPos(i - 1, a[i]);
            if (pos == 0) {
                dp[i] = 0;
                par[0][i] = 0;
            } else {
                dp[i] = dp[pos - 1] + 1;
                par[0][i] = pos - 1;
            }

            res += dp[i];

            for (int j = 1; j < LOG; j++) {
                par[j][i] = par[j - 1][par[j - 1][i]];
            }

            root[i] = add(root[par[0][i]], 1, n, a[i]);
        }
        cout << res << '\n';
    }
    return 0;
}