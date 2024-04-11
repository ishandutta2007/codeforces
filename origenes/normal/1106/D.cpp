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

int n, m;
vector<int> G[maxn], ans;
bool vis[maxn];

int main() {
    scanf("%d%d", &n, &m);
    FOR(i, 1, m) {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].eb(v);
        G[v].eb(u);
    }
    set<int> s;
    s.insert(1);
    while (!s.empty()) {
        int u = *s.begin(); s.erase(u);
        ans.eb(u);
        vis[u] = true;
        for (int v : G[u]) if (!vis[v]) s.insert(v);
    }
    for (int u : ans) printf("%d ", u);
}