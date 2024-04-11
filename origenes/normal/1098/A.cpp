#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define sqr(x) ((x) * (x))
#define all(x) (x).begin(), (x).end()
#define reset(x, y) memset(x, y, sizeof(x))
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second

const int maxn = 112345;
const int inf = 0x3f3f3f3f;

vector<int> G[maxn];
int s[maxn], a[maxn], n;

void dfs(int u, int tot) {
    if (s[u] != -1) {
        a[u] = s[u] - tot;
        for (int v : G[u]) dfs(v, s[u]);
    } else {
        if (G[u].empty()) {
            a[u] = 0;
            return;
        }
        int mmin = inf;
        for (int v : G[u]) mmin = min(mmin, s[v]);
        a[u] = mmin - tot;
        for (int v : G[u]) dfs(v, mmin);
    }
}

int main() {
    scanf("%d", &n);
    FOR(i, 2, n) {
        int p;
        scanf("%d", &p);
        G[p].eb(i);
    }
    FOR(i, 1, n) scanf("%d", s + i);
    dfs(1, 0);
    ll ans = 0;
    FOR(i, 1, n) {
        if (a[i] < 0) {
            ans = -1;
            break;
        }
        ans += a[i];
    }
    printf("%lld", ans);
}