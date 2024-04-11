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

#define dist(x1, y1, x2, y2) min(abs(x1 - x2), abs(y1 - y2))
#define mandist(x1, y1, x2, y2) (abs(x1 - x2) + abs(y1 - y2))

const int maxn = 1e5 + 10;
set<pll> s;
map<int, int> xvec[maxn],
    yvec[maxn];
vector<pll> adj[maxn];
vector<int> xall, yall;
int x[maxn],
    y[maxn];
LL dis[maxn];
int n, m;
LL sx, sy, fx, fy;

void add_edges(map<int, int> &xmp, int w, int y, int id) {
    auto lit = xmp.lower_bound(y);
    auto rit = xmp.upper_bound(y);
    if (lit != xmp.begin()) lit--;
    while (lit != rit) {
        adj[id].PB(MP(lit->R, w));
        lit++;
    }
    if (lit != xmp.end())
        adj[id].PB(MP(lit->R, w));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
    cin >> n >> m;
    cin >> sx >> sy >> fx >> fy;
    for (int i = 0; i < m; i++) {
        cin >> x[i] >> y[i];
        xall.PB(x[i]);
        yall.PB(y[i]);
    }
    sort(all(xall));
    xall.resize(unique(all(xall)) - xall.begin());
    sort(all(yall));
    yall.resize(unique(all(yall)) - yall.begin());
    for (int i = 0; i < m; i++) {
        dis[i] = dist(sx, sy, x[i], y[i]);
        x[i] = lower_bound(all(xall), x[i]) - xall.begin();
        y[i] = lower_bound(all(yall), y[i]) - yall.begin();
        xvec[x[i]][y[i]] = i;
        yvec[y[i]][x[i]] = i;
    }
    for (int i = 0; i < m; i++) {
        if (x[i] - 1 >= 0)
            add_edges(xvec[x[i] - 1], xall[x[i]] - xall[x[i] - 1], y[i], i);
        add_edges(xvec[x[i]], 0, y[i], i);
        if (x[i] + 1 < sz(xall))
            add_edges(xvec[x[i] + 1], xall[x[i] + 1] - xall[x[i]], y[i], i);

        if (y[i] - 1 >= 0)
            add_edges(yvec[y[i] - 1], yall[y[i]] - yall[y[i] - 1], x[i], i);
        add_edges(yvec[y[i]], 0, x[i], i);
        if (y[i] + 1 < sz(yall))
            add_edges(yvec[y[i] + 1], yall[y[i] + 1] - yall[y[i]], x[i], i);

        s.insert(MP(dis[i], i));
    }
    while (sz(s)) {
        int u = s.begin()->R;
        s.erase(s.begin());
        for (auto e : adj[u]) {
            int v = e.L;
            int w = e.R;
            if (dis[u] + w < dis[v]) {
                s.erase(MP(dis[v], v));
                dis[v] = dis[u] + w;
                s.insert(MP(dis[v], v));
            }
        }
    }
    LL ans = mandist(sx, sy, fx, fy);
    for (int i = 0; i < m; i++)
        smin(ans, dis[i] + mandist(fx, fy, xall[x[i]], yall[y[i]]));
    cout << ans << '\n';
	return 0;
}