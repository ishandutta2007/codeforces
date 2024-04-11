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

int n, m, k, p[maxn], cnt[maxn], x;
vector<pair<int, pii>> edges;

int Find(int x) {
    return p[x] == x ? x : p[x] = Find(p[x]);
}

int main() {
    scanf("%d%d%d", &n, &m, &k);
    FOR(i, 1, k) {
        scanf("%d", &x);
        cnt[x]++;
    }
    FOR(i, 1, m) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        edges.pb(mp(w, mp(u, v)));
    }
    sort(all(edges));
    FOR(i, 1, n) p[i] = i;
    int ans = 0;
    for (auto e : edges) {
        int u = Find(e._2._1), v = Find(e._2._2);
        if (u == v) continue;
        p[u] = v;
        if (cnt[u] && cnt[v]) ans = e._1;
        cnt[v] += cnt[u];
    }
    FOR(i, 1, k) printf("%d ", ans);
}