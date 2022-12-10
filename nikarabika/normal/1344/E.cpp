//sobskdrbhvk
//remember...
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

const int maxn = 100 * 1000 + 10,
      maxl = 20,
      maxg = maxn * maxl;
const LL INF = 1e18;
int siz[maxn],
    pos[maxn],
    grp[maxn];
LL h[maxn],
   wei[maxg],
   tim[maxn],
   vert[maxg];
set<int> *s[maxn];
vector<pll> reqs;
vector<pii> adj[maxn];
vector<int> vec[maxn];
int n, m, grpcnt;

void dfs(int u, int p = -1) {
    siz[u] = 1;
    for (auto e: adj[u])
        if (e.L != p) {
            h[e.L] = h[u] + e.R;
            dfs(e.L, u);
            siz[u] += siz[e.L];
            pos[u] = e.L;
        }
}

void get_reqs(int u) {
    for (auto e: adj[u])
        get_reqs(e.L);
    if (sz(adj[u]) == 0)
        s[u] = new set<int>;
    else {
        s[u] = s[adj[u][0].L];
        int basegrp = grpcnt;
        vector<int> checks;
        for (int i = 0; i < sz(adj[u]); i++) {
            int v = adj[u][i].L,
                w = adj[u][i].R;
            vert[grpcnt] = v;
            wei[grpcnt] = w;
            if (i == 0) {
                grpcnt++;
                continue;
            }
            for (int t: *s[v]) {
                grp[t] = grpcnt;
                s[u]->insert(t);
                checks.PB(t);
            }
            s[v]->clear();
            grpcnt++;
        }
        for (auto t: checks) {
            int gt = max(basegrp, grp[t]);
            auto it = s[u]->upper_bound(t);
            if (it != s[u]->end()) {
                int tt = *it;
                int gtt = max(basegrp, grp[tt]);
                if (gtt < gt)
                    reqs.PB(MP(h[u] + tim[t] + 1, h[u] + tim[tt]));
            }
            if (it == s[u]->begin()) continue;
            it--;
            if (it == s[u]->begin()) continue;
            it--;
            int tt = *it;
            int gtt = max(basegrp, grp[tt]);
            if (gtt < gt)
                reqs.PB(MP(h[u] + tim[tt] + 1, h[u] + tim[t]));
        }
        if (sz(*s[u])) {
            int t = *s[u]->begin();
            int gt = max(basegrp, grp[t]);
            if (vert[gt] != pos[u])
                reqs.PB(MP(1, h[u] + tim[t]));
        }
    }
    for (auto t: vec[u])
        s[u]->insert(t);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i < n; i++) {
        int fi, se, th;
        cin >> fi >> se >> th;
        fi--, se--;
        adj[fi].PB(MP(se, th));
        adj[se].PB(MP(fi, th));
    }
    dfs(0);
    for (int i = 0; i < n; i++) {
        sort(all(adj[i]), [](pii i, pii j) -> bool { return siz[i.L] < siz[j.L]; });
        if (i)
            adj[i].pop_back();
        reverse(all(adj[i]));
    }
    for (int i = 0; i < m; i++) {
        int fi, se;
        cin >> fi >> se;
        fi--;
        tim[i] = se;
        vec[fi].PB(i);
    }
    get_reqs(0);
    sort(all(reqs));
    multiset<LL> deadlines;
    LL curt = 0;
    LL ans = INF;
    for (int i = 0; i < sz(reqs); i++) {
        if (curt < reqs[i].L)
            curt = reqs[i].L;
        deadlines.insert(reqs[i].R);
        while (sz(deadlines) and (i + 1 == sz(reqs) or curt < reqs[i + 1].L)) {
            if (curt > *deadlines.begin())
                smin(ans, *deadlines.begin());
            deadlines.erase(deadlines.begin());
            curt++;
        }
    }
    if (ans == INF)
        cout << -1 << ' ' << sz(reqs) << '\n';
    else {
        cout << ans << ' ';
        int cnt = 0;
        for (auto req: reqs)
            cnt += req.R < ans;
        cout << cnt << '\n';
    }
	return 0;
}