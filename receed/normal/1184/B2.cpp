#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <random>
#include <bitset>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using ld = long double;

const int N = 101, M = 1001;
int d[N][N];
vector<int> g[M];
int sx[M], sa[M], sf[M], bx[M], bd[M];
int used[M], pr[M], inp[M];

int dfs(int v) {
    used[v] = 1;
    for (int u : g[v])
        if (pr[u] == -1 || !used[pr[u]] && dfs(pr[u])) {
            pr[u] = v;
            return 1;
        }
    return 0;
}

int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m, u, v;
    cin >> n >> m;
    rep(i, n)
        rep(j, n)
            d[i][j] = N;
    rep(i, m) {
        cin >> u >> v;
        u--; v--;
        d[u][v] = d[v][u] = 1;
    }
    rep(i, n)
        rep(j, n)
            rep(k, n)
                d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
    int s, b;
    ll k, h;
    cin >> s >> b >> k >> h;
    rep(i, s)
        cin >> sx[i] >> sa[i] >> sf[i];
    rep(i, b)
        cin >> bx[i] >> bd[i];
    rep(i, s)
        rep(j, b)
            if (sa[i] >= bd[j] && d[sx[i]][bx[j]] <= sf[i])
                g[i].push_back(j);
    rep(i, b)
        pr[i] = -1;
    int res = 0;
    while (1) {
        int res1 = res;
        memset(used, 0, s * sizeof(int));
        rep(i, s)
            if (!used[i] && !inp[i] && dfs(i)) {
                inp[i] = 1;
                res++;
            }
        if (res == res1)
            break;
    }
    cout << min(res * k, s * h);
}