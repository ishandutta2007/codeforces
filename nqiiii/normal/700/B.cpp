#include <bits/stdc++.h>
using namespace std;
typedef long long Long;
const int maxN = 200000;
int n, k, sz[maxN + 10], val[maxN + 10], dep[maxN + 10];
vector<int> g[maxN + 10];
Long ans;

void Dfs(int p, int f) {
    dep[p] = dep[f] + 1;
    ans += 1ll * val[p] * dep[p];
    sz[p] = val[p];
    for (int i = 0; i < g[p].size(); ++i) {
        int e = g[p][i];
        if (e != f) {
            Dfs(e, p); sz[p] += sz[e];
        }
    }
}

void DfsAns(int p, int f, int k) {
    int sum = val[p], maxV = 0, now;
    for (int i = 0; i < g[p].size(); ++i) {
        int e = g[p][i];
        if (e != f) {
            sum += sz[e]; maxV = max(maxV, sz[e]);
        }
    }
    if (maxV * 2 > sum) now = (sum - maxV) * 2;
    else now = sum;
    if (now < k) {
        ans -= 1ll * dep[p] * now;
        for (int i = 0; i < g[p].size(); ++i) {
            int e = g[p][i];
            if (e != f && sz[e] == maxV) {
                DfsAns(e, p, k - now);
            }
        }
    } else ans -= 1ll * dep[p] * k;
}

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= k * 2; ++i) {
        int p; scanf("%d", &p); ++val[p];
    }
    for (int i = 1; i < n; ++i) {
        int l, r; scanf("%d%d", &l, &r);
        g[l].push_back(r); g[r].push_back(l);
    }
    Dfs(1, 0);
    DfsAns(1, 0, k * 2);
    printf("%lld", ans);
}