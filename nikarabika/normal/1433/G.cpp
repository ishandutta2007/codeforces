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

const int maxn = 1000 + 10;
vector<int> adj[maxn];
int frm[maxn],
    too[maxn],
    wei[maxn],
    couL[maxn],
    couR[maxn];
int n, m, k;

void dijkstra(int src, int *dis) {
    set<pii> s;
    memset(dis, 63, n * 4);
    dis[src] = 0;
    s.insert(MP(0, src));
    while (sz(s)) {
        int u = s.begin()->R;
        s.erase(s.begin());
        for (auto e: adj[u]) {
            int v = frm[e] ^ too[e] ^ u;
            int w = wei[e];
            if (dis[u] + w < dis[v]) {
                s.erase(MP(dis[v], v));
                dis[v] = dis[u] + w;
                s.insert(MP(dis[v], v));
            }
        }
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int fi, se, th;
        cin >> fi >> se >> th;
        frm[i] = --fi;
        too[i] = --se;
        wei[i] = th;
        adj[fi].PB(i);
        adj[se].PB(i);
    }
    int dis[n][n];
    for (int i = 0; i < n; i++)
        dijkstra(i, dis[i]);
    int ans = 0;
    for (int i = 0; i < k; i++) {
        cin >> couL[i] >> couR[i];
        couL[i]--, couR[i]--;
        ans += dis[couL[i]][couR[i]];
    }
    for (int i = 0; i < m; i++) {
        int curans = 0;
        for (int j = 0; j < k; j++)
            curans += min(dis[couL[j]][couR[j]],
                    min(dis[couL[j]][frm[i]] + dis[couR[j]][too[i]],
                    dis[couL[j]][too[i]] + dis[couR[j]][frm[i]]));
        smin(ans, curans);
    }
    cout << ans << '\n';
	return 0;
}