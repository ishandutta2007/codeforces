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

vector<int> G[maxn];
queue<pii> q;
int s[maxn];
int n, m;

int main() {
    scanf("%d%d", &n, &m);
    FOR(i, 1, n) {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].pb(v);
    }
    FOR(i, 1, 100000) {
        sort(all(G[i]), greater<int>());
        if (G[i].size() && G[i].front() > 0) q.push(mp(i, 1));
    }
    int ans = 0, lvl = 1, now = 0;
    while (!q.empty()) {
        auto u = q.front(); q.pop();
        if (u._2 > lvl) {
            ans = max(ans, now);
            now = 0;
            lvl++;
        }
        int v = u._1;
        if (s[v] + G[v][lvl - 1] > 0) {
            s[v] += G[v][lvl - 1];
            now += s[v];
            if (G[v].size() > lvl) q.push(mp(v, lvl + 1));
        }
    }
    ans = max(ans, now);
    printf("%d", ans);
}