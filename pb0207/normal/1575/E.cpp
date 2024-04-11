#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int p = 1e9 + 7;
const int N = 2e5 + 10;
int n, k, a[N];
vector<pii> g[N];
inline void A(int &x, int y) {
    x = (x + y >= p ? x + y - p : x + y);
}
inline void U(int &x, int y) {
    x = (x > y ? x : y);
}
int del[N], si[N];
int mnsi, mnid;
inline void GetSi(int x, int fa) {
    si[x] = 1;
    for (auto e: g[x]) if (e.second != fa && !del[e.second]) {
        GetSi(e.second, x);
        si[x] += si[e.second];
    }
}
inline void GetMx(int x, int fa, int al) {
    int mx = al - si[x];
    for (auto e: g[x]) if (e.second != fa && !del[e.second]) {
        mx = max(mx, si[e.second]);
        GetMx(e.second, x, al);
    }
    if (mx < mnsi) mnsi = mx, mnid = x;
}
struct DS {
    int f[N];
    inline void Add(int x, int y) {
        for (int i = x; i <= n; i += (i & -i)) A(f[i], y);
    }
    inline void Clr(int x) {
        for (int i = x; i <= n; i += (i & -i)) f[i] = 0;
    }
    inline int Ask(int x) {
        int ans = 0;
        for (int i = x; i; i -= (i & -i)) A(ans, f[i]);
        return ans;
    }
} f1, g1, f2, g2;
int sw1, sw2;
int ans;
void PushIn(int x, int fa, int fe, int sm, int sw, DS &f, DS &G, int &mxsw) {
    if (sw > k) return;
    mxsw = max(mxsw, sw);
    A(sm, a[x]);
    f.Add(sw + 1, sm);
    G.Add(sw + 1, 1);
    for (auto e: g[x]) {
        int y = e.second, z = e.first;
        if (del[y] || y == fa) continue;
        PushIn(y, x, z, sm, sw + (fe != z), f, G, mxsw);
    }
}
void Calc(int x, int fa, int fe, int sm, int sw) {
    if (sw > k) return;
    A(sm, a[x]);
    if (sw < k) ans = (ans + 1ll * sm * (g1.Ask(k - sw) - g2.Ask(k - sw)) + (f1.Ask(k - sw) - f2.Ask(k - sw))) % p;
    ans = (ans + 1ll * sm * g2.Ask(k - sw + 1) + f2.Ask(k - sw + 1)) % p;
    for (auto e: g[x]) {
        int y = e.second, z = e.first;
        if (del[y] || y == fa) continue;
        Calc(y, x, z, sm, sw + (fe != z));
    }
}
inline void Solve(int x) {
    GetSi(x, 0); 
    mnsi = 1e9; GetMx(x, 0, si[x]);
    int u = mnid;
    // int u = x;
    // printf("Solve %d\n", u);
    sw1 = 0, sw2 = 0;
    f1.Add(1, a[u]); f2.Add(1, a[u]);
    g1.Add(1, 1); g2.Add(1, 1);
    A(ans, a[u]);
    int la = -1;
    for (auto e: g[u]) {
        int y = e.second, z = e.first;
        if (z != la) {
            for (int i = 1; i <= sw2 + 1; ++i) f2.Clr(i), g2.Clr(i);
            sw2 = 0; la = z; f2.Add(1, a[u]); g2.Add(1, 1);
        }
        if (del[y]) continue;
        Calc(y, u, z, 0, 0);
        PushIn(y, u, z, a[u], 0, f1, g1, sw1);
        PushIn(y, u, z, a[u], 0, f2, g2, sw2);
        // printf("- %d %d\n", y, ans);
    }
    // printf("ans = %d\n", ans);
    for (int i = 1; i <= sw1 + 1; ++i) f1.Clr(i), g1.Clr(i);
    for (int i = 1; i <= sw2 + 1; ++i) f2.Clr(i), g2.Clr(i);
    del[u] = 1;
    for (auto e: g[u]) if (!del[e.second]) Solve(e.second);
}
inline void Dfs(int x, int fa, int fe, int sw, int sm, int rt) {
    if (sw > k) return; 
    A(sm, a[x]);
    if (x <= rt) A(ans, p - sm);
    for (auto e: g[x]) {
        int y = e.second, z = e.first;
        if (y == fa) continue;
        Dfs(y, x, z, sw + (fe != z), sm, rt);
    }    
}
int main() {
    scanf("%d%d", &n, &k);
    // int seed = 1634296499;
    // srand(seed);
    // cout << "Seed = " << seed << endl;
    // n = 100, k = 10;
    for (int i = 1; i <= n; ++i) scanf("%d", a + i);
    // for (int i = 1; i <= n; ++i) a[i] = rand() % 10, printf("%d ", a[i]);
    // puts("");
    for (int i = 1, x, y, z; i < n; ++i) {
        scanf("%d%d%d", &x, &y, &z);
        // x = rand() % i + 1, y = i + 1, z = rand() & 1; 
        // printf("%d %d %d\n", x, y, z);
        g[x].push_back(pii(z, y));
        g[y].push_back(pii(z, x));
    }
    for (int i = 1; i <= n; ++i) sort(g[i].begin(), g[i].end());
    Solve(1);
    if (ans < 0) ans += p;
    printf("%d\n", ans);

    // Check
    // for (int i = 1; i <= n; ++i) {
    //     ans -= a[i];
    //     for (auto e: g[i]) Dfs(e.second, i, e.first, 0, a[i], i);
    //     // cout << i << ' ' << ans << endl;
    // }
    // cout << ans << endl;
    return 0;
}