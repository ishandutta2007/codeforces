#include <bits/stdc++.h>
using namespace std;
const int maxN = 100000, mod = 1000000007;

int Add(int x, int y) {
    x += y; return x < mod ? x : x - mod;
}
int Dec(int x, int y) {
    x -= y; return x < 0 ? x + mod : x;
}
int Mul(int x, int y) {
    return 1ll * x * y % mod;
}
int Fpow(int x, int y = mod - 2) {
    int ans = 1;
    while (y) {
        if (y % 2) ans = Mul(ans, x);
        y /= 2; x = Mul(x, x);
    }
    return ans;
}

int n, co[maxN + 10], f[maxN + 10][2];
vector<int> g[maxN + 10];

void Dfs(int p, int fa) {
    f[p][0] = 1;
    for (int i = 0; i < g[p].size(); ++i) {
        int e = g[p][i];
        if (e != fa) {
            Dfs(e, p);
            f[p][0] = Mul(f[p][0], Add(f[e][0], f[e][1]));
        }
    }
    if (co[p]) {
        f[p][1] = f[p][0]; f[p][0] = 0;
    } else {
        for (int i = 0; i < g[p].size(); ++i) {
            int e = g[p][i];
            if (e != fa) {
                f[p][1] = Add(f[p][1], Mul(f[p][0], Mul(f[e][1], Fpow(Add(f[e][0], f[e][1])))));
            }
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 2; i <= n; ++i) {
        int p; scanf("%d", &p);
        g[p + 1].push_back(i);
        g[i].push_back(p + 1);
    } 
    for (int i = 1; i <= n; ++i) scanf("%d", &co[i]);
    Dfs(1, 0);
    printf("%d", f[1][1]);
}