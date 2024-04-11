#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define PB push_back
#define fi first
#define se second
#define MP make_pair
const int P = 998244353;
const int V = 1510;

int SZ;
int a[V][V], f[V * 2], mx, T[V], ok[V * 2], cnt[V * 2];
vector<int> g[V * 2];
vector<int> s[V * 2];
int fd(int x) {
    if (x != f[x]) f[x] = fd(f[x]);
    return f[x];
}
void U(int x, int y) {
    int px = fd(x);
    int py = fd(y);
    if (px == py) return;
    ++SZ;
    for (int i = 0; i < s[px].size(); ++i) s[SZ].PB(s[px][i]);
    for (int i = 0; i < s[py].size(); ++i) s[SZ].PB(s[py][i]);
    f[SZ] = SZ;
    f[px] = SZ;
    f[py] = SZ;
    cnt[SZ] = cnt[px] + cnt[py];
    ok[SZ] = false;
    g[SZ].PB(px);
    g[SZ].PB(py);

}

vector<PII> w[V * V];
int dp[V * 2][V], n, c[V * 2], tmp[V * 2][V];

void dfs(int u) {
    for (int i = 0; i <= n; ++i) dp[u][i] = 0;
    dp[u][0] = 1;
    c[u] = 0;
    if (g[u].size() == 0) {
        dp[u][0] = 0;
        dp[u][1] = 1;
        c[u]++;
        return;
    }
    for (int i = 0; i < g[u].size(); ++i) {
        int v = g[u][i];
        //printf("DFS %d %d %d %d\n", u, v, ok[u], ok[v]);
        dfs(v);
        for(int j = 0; j <= c[u] + c[v]; ++j) tmp[u][j] = 0;
        for (int j = 0; j <= c[u]; ++j) {
            for (int k = 0; k <= c[v]; ++k) {
                tmp[u][j + k] += (LL) dp[u][j] * dp[v][k] % P;
                tmp[u][j + k] %= P;
            }
        }
        for(int j = 0; j <= c[u] + c[v]; ++j) dp[u][j] = tmp[u][j];
        c[u] += c[v];
    }
    if (ok[u]) dp[u][1] = (dp[u][1] + 1) % P;
}

int bel[2][V];
int main() {
    while (~scanf("%d", &n)) {
        int M = n * (n - 1) / 2;
        for (int i = 0; i <= M; ++i) w[i].clear();
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                scanf("%d", &a[i][j]);
            }
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j < i; ++j) {
                w[a[i][j]].PB(MP(j, i));
            }
        }
        for (int i = 1; i <= n; ++i) f[i] = i;
        SZ = n;
        for (int i = 1; i <= 2 * n; ++i) g[i].clear(), s[i].clear();
        for (int i = 1; i <= n; ++i) s[i].PB(i), cnt[i] = 0;
        for (int i = 1; i <= n; ++i) bel[0][i] = i, T[i] = 0;
        int pre = 0, cur = 1;
        mx = 0;
        while (mx <= M) {
            bool has = false;
            int tmp = mx;
            while (tmp <= mx) {
                for (int j = 0; j < w[tmp].size(); ++j) {
                    int u = w[tmp][j].fi;
                    int v = w[tmp][j].se;
                    if (fd(u) != fd(v)) {
                        U(u, v);
                        has = true;
                    }
                    int cp = fd(u);
                    cnt[cp]++;
                    if (cnt[cp] == s[cp].size() * (s[cp].size() - 1) / 2) ok[cp] = true;
                }
                ++tmp;
            }
            if (!has) {++mx; continue;}
            cur = 1 - pre;
            for (int i = 1; i <= n; ++i) bel[cur][i] = fd(i);
            /*
            map<PII, int> mp;
            for (int i = 1; i <= n; ++i) {
                int u =bel[cur][i];
                int v = bel[pre][i];
                if (u != v && mp.find(MP(u, v)) == mp.end()) {
                    g[u].PB(v);
                    mp[MP(u, v)] = 1;
                }
            }*/
            pre = cur;
            ++mx;
        }
        //for (int i = 1; i <= SZ; ++i, printf("G %d %d\n", i - 1, T[i - 1])) for(int j = 0; j < g[i].size(); ++j) printf("%d ", g[i][j]);
        dfs(SZ);
        for (int i = 1; i <= n; ++i) printf("%d ", dp[SZ][i]); puts("");
    }
    return 0;
}

/*
4
0 3 4 6
3 0 2 1
4 2 0 5
6 1 5 0

7
0 1 18 15 19 12 21
1 0 16 13 17 20 14
18 16 0 2 7 10 9
15 13 2 0 6 8 11
19 17 7 6 0 4 5
12 20 10 8 4 0 3
21 14 9 11 5 3 0
*/