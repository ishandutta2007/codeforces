#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define all(x) (x).begin(), (x).end()
#define reset(x, y) memset(x, y, sizeof(x))
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second

const int maxn = 123456;

vector<int> G[maxn];
bool ans[maxn], vis[maxn];
int pos[maxn], a[maxn];
int n;

bool dfs(int u) {
    if (vis[u]) return ans[u];
    vis[u] = true;
    ans[u] = false;
    for (int v : G[u])
        if (!dfs(v)) ans[u] = true;
    return ans[u];
}

int main() {
    scanf("%d", &n);
    FOR(i, 1, n) {
        scanf("%d", &a[i]);
        pos[a[i]] = i;
    }
    ROF(i, n, 1) {
        for (int j = pos[i] - i; j > 0; j -= i) if (a[j] > i) G[i].pb(a[j]);
        for (int j = pos[i] + i; j <= n; j += i) if (a[j] > i) G[i].pb(a[j]);
    }
    FOR(i, 1, n) putchar(dfs(a[i]) ? 'A' : 'B');
    puts("");
    return 0;
}