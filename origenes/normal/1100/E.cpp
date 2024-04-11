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
vector<pair<pii, int>> e;
int n, m, deg[maxn], seq[maxn];

bool check(int lmt) {
    FOR(i, 1, n) G[i].clear();
    reset(deg, 0);
    int cnt = 0;
    for (auto now : e) if (now._2 > lmt) {
            G[now._1._1].eb(now._1._2);
            deg[now._1._2]++;
        }
    queue<int> q;
    FOR(i, 1, n) if (!deg[i]) {
            seq[i] = ++cnt;
            q.push(i);
        }
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : G[u]) {
            deg[v]--;
            if (!deg[v]) {
                seq[v] = ++cnt;
                q.push(v);
            }
        }
    }
    return cnt == n;
}

int main() {
    scanf("%d%d", &n, &m);
    FOR(i, 1, m) {
        int u, v, c;
        scanf("%d%d%d", &u, &v, &c);
        e.eb(mp(u, v), c);
    }
    int l = 0, r = 1e9;
    while (l < r) {
        int m = l + (r - l >> 1);
        if (check(m)) r = m;
        else l = m + 1;
    }
    check(l);
    vector<int> ans;
    REP(i, m) if (seq[e[i]._1._1] > seq[e[i]._1._2]) ans.eb(i);
    printf("%d %d\n", l, int(ans.size()));
    for (auto now : ans) printf("%d ", now + 1);
}