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
#define mp make_pair
#define _1 first
#define _2 second

const int maxn = 212345;

int n, m, k, deg[maxn];
set<pii> s;
set<int> G[maxn];
vector<pii> e;
vector<int> ans;

void maintain() {
    while (!s.empty()) {
        pii now = *s.begin();
        if (now._1 >= k) return;
        int u = now._2;
        s.erase(s.begin());
        for (int v : G[u]) {
            if (s.count({deg[v], v})) {
                s.erase({deg[v], v});
                s.insert({--deg[v], v});
                G[v].erase(u);
            }
        }
    }
}

int main() {
    scanf("%d%d%d", &n, &m, &k);
    REP(i, m) {
        int u, v;
        scanf("%d%d", &u, &v);
        s.erase(mp(deg[u], u));
        s.erase(mp(deg[v], v));
        s.insert({++deg[u], u});
        s.insert({++deg[v], v});
        G[u].insert(v);
        G[v].insert(u);
        e.pb({u, v});
    }
    maintain();
    reverse(all(e));
    REP(i, m) {
        ans.pb(s.size());
        int u = e[i]._1, v = e[i]._2;
        if (s.count({deg[u], u}) && s.count({deg[v], v})) {
            s.erase({deg[u], u});
            s.erase({deg[v], v});
            s.insert({--deg[u], u});
            s.insert({--deg[v], v});
            G[u].erase(v);
            G[v].erase(u);
            maintain();
        }
    }
    reverse(all(ans));
    for (auto it : ans) printf("%d\n", it);
    return 0;
}