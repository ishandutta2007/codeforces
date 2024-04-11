#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define all(x) (x).begin(), (x).end()
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define mp make_pair
#define _1 first
#define _2 second

const int maxn = 1234567;
int n, d[maxn], ans[maxn];
vector<int> G[maxn];
map<int, int> mmap[maxn];

void dfs(int u, int p) {
    d[u] = d[p] + 1;
    mmap[u][d[u]]++;
    ans[u] = d[u];
    for (int v : G[u]) {
        if (v == p) continue;
        dfs(v, u);
        if (mmap[u].size() < mmap[v].size()) {
            swap(mmap[u], mmap[v]);
            ans[u] = ans[v];
        }
        for (const auto &cur : mmap[v]) {
            mmap[u][cur.first] += cur.second;
            if (mmap[u][cur.first] + (cur.first < ans[u]) > mmap[u][ans[u]])
                ans[u] = cur.first;
        }
        mmap[v].clear();
    }
}

int main() {
    scanf("%d", &n);
    REP(i, n - 1) {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].pb(v);
        G[v].pb(u);
    }
    dfs(1, 0);
    FOR(i, 1, n) printf("%d\n", ans[i] - d[i]);
    return 0;
}