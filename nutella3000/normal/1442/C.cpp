#include <bits/stdc++.h>
 
using namespace std;
 
//#define aidar asadulin
 
//#define int long long
#define ll long long
#define mp make_pair
#define pii pair<int, int>
#define pip pair<int, pii>
#define fi first
#define se second
#define all(_v) _v.begin(), _v.end()
#define sz(a) (int) (a.size())
#define chkmax(a, b) a = max(a, b)
#define chkmin(a, b) a = min(a, b)
#define ld long double
 
const int inf = 1e9 + 7;
const int mod = 998244353;
const int max_n = 2e5 + 1, log_n = 20;

int n;
vector<int> gr[max_n], g[max_n];
vector<vector<int>> dist;


int binpow(ll a, int b) {
    ll res = 1;
    for(;b > 0;b /= 2, a = a * a % mod) 
        if (b & 1) res = res * a % mod;
    return res;
}

int djkstra() {
    dist.resize(max_n, vector<int>(log_n, inf));

    dist[0][0] = 0;

    auto comp = [dist](pii v1, pii v2) {
        if (dist[v1.fi][v1.se] == dist[v2.fi][v2.se]) return v1 < v2;
        return dist[v1.fi][v1.se] < dist[v2.fi][v2.se];
    };

    set<pii, decltype(comp)> a(comp);

    a.emplace(0, 0);

    while(sz(a)) {
        pii v = (*a.begin());
        a.erase(a.begin());


        for(int i : (v.se % 2 == 0 ? gr[v.fi] : g[v.fi])) {
            int val = dist[v.fi][v.se] + 1;

            if (val < dist[i][v.se]) {
                a.erase(mp(i, v.se));
                dist[i][v.se] = val;
                a.emplace(mp(i, v.se));
            }
        }

        if (v.se == log_n - 1) continue;

        int val = dist[v.fi][v.se] + (1 << v.se);
        if (dist[v.fi][v.se + 1] > val) {
            a.erase(mp(v.fi, v.se + 1));
            dist[v.fi][v.se + 1] = val;
            a.emplace(mp(v.fi, v.se + 1));
        }
    }

    int res = inf;
    for(int i : dist[n - 1]) chkmin(res, i);

    return res;
}

pii bfs() {
    vector<vector<pii>> dist(n, vector<pii>(2, mp(inf, inf)));
    deque<pii> bfs;
    bfs.emplace_back(0, 0);
    dist[0][0] = mp(0, 0);

    while(sz(bfs)) {
        pii v = bfs.front();
        //cout << v.fi << " " << v.se << " " << dist[v.fi][v.se].fi << " " << " " << dist[v.fi][v.se].se << endl;
        bfs.pop_front();

        for(int i : (v.se == 0 ? gr[v.fi] : g[v.fi])) {
            pii val = mp(dist[v.fi][v.se].fi, dist[v.fi][v.se].se + 1);
            if (dist[i][v.se] > val) {
                dist[i][v.se] = val;
                bfs.emplace_front(mp(i, v.se));
            }
        }

        pii val = mp(dist[v.fi][v.se].fi + 1, dist[v.fi][v.se].se);

        if (dist[v.fi][1 - v.se] > val) {
            dist[v.fi][1 - v.se] = val;
            bfs.emplace_back(mp(v.fi, 1 - v.se));
        }
    }
    return min(dist[n - 1][0], dist[n - 1][1]);
}

void solve() {
    int m;
    cin >> n >> m;
    for(int i = 0;i < m;i++) {
        int v1, v2;
        cin >> v1 >> v2;
        v1--; v2--;
        gr[v1].emplace_back(v2);
        g[v2].emplace_back(v1);
    }

    ll res = djkstra();

    if (res == inf) {
        pii temp = bfs();
        res = (temp.se + binpow(2, temp.fi) - 1 + mod) % mod;
    }

    cout << res;
}


signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    solve();
}