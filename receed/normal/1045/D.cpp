#include <cstdio>
#include <vector>   
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <random>
#include <ctime>
#include <iomanip>
#include <deque>
#include <queue> 
#include <cmath>
#include <cstring>
#include <cassert>
#include <bitset>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int N = 100001;
ld a[N], s[N], ans;
int p[N];
vector<int> g[N];

void dfs(int v, int pr) {
    p[v] = pr;
    for (int u : g[v])
        if (u != pr) {
            dfs(u, v);
            s[v] += a[u];
        }
    ans -= a[v] * s[v];
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
#else
    //freopen("wikipidia.in", "r", stdin); 
    //freopen("wikipidia.out", "w", stdout);
#endif
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, q, u, v;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%Lf", &a[i]);
        a[i] = 1 - a[i];
        ans += a[i];
    }
    for (int i = 1; i < n; i++) {
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0, -1);
    scanf("%d", &q);
    ld np;
    for (int i = 0; i < q; i++) {
        scanf("%d%Lf", &v, &np);
        np = 1 - np;
        ans += (np - a[v]) * (1 - s[v]);
        if (v > 0) {
            ans += (a[v] - np) * a[p[v]];
            s[p[v]] += np - a[v];
        }
        a[v] = np;
        printf("%.6Lf\n", ans);
    }
}