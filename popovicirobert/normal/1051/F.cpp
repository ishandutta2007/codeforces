#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll INF = 1e18;
const int MAXN = (int) 1e5;
const int DIM = 50;
const int LOG = 18;

int sef[MAXN + 1];

int myfind(int x) {
    if(sef[x] == 0)
        return x;
    return sef[x] = myfind(sef[x]);
}

inline void myunion(int x, int y) {
    x = myfind(x), y = myfind(y);
    if(x != y) {
        sef[x] = y;
    }
}

vector < pair <int, int> > g[MAXN + 1];

int rmq[2 * MAXN + 1][LOG + 1], first[MAXN + 1], sz;
int lvl[MAXN + 1], lg[2 * MAXN + 1];
ll dist[MAXN + 1];

void dfs(int nod, int par) {
    rmq[++sz][0] = nod;
    first[nod] = sz;
    for(auto it : g[nod]) {
        if(it.first != par) {
            dist[it.first] = dist[nod] + it.second;
            lvl[it.first] = lvl[nod] + 1;
            dfs(it.first, nod);
            rmq[++sz][0] = nod;
        }
    }
}

inline int get_lca(int x, int y) {
    x = first[x], y = first[y];
    if(x > y) {
        swap(x, y);
    }
    int bit = lg[y - x + 1];
    if(lvl[rmq[x][bit]] < lvl[rmq[y - (1 << bit) + 1][bit]])
        return rmq[x][bit];
    return rmq[y - (1 << bit) + 1][bit];
}

inline ll get_dist(int x, int y) {
    int nod = get_lca(x, y);
    return dist[x] + dist[y] - 2 * dist[nod];
}

ll dp[2][DIM][DIM];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, j, n, m, q;
    ios::sync_with_stdio(false);
    cin >> n >> m;
    vector <int> nodes;
    map < pair <int, int>, int > mp;
    for(i = 1; i <= m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        if(myfind(x) != myfind(y)) {
            myunion(x, y);
            g[x].push_back({y, z});
            g[y].push_back({x, z});
        }
        else {
            nodes.push_back(x);
            nodes.push_back(y);
            mp[{x, y}] = mp[{y, x}] = z;
        }
    }
    sort(nodes.begin(), nodes.end());
    nodes.resize(unique(nodes.begin(), nodes.end()) - nodes.begin());
    lvl[1] = 1;
    dfs(1, 0);
    for(i = 2; i <= sz; i++) {
        lg[i] = lg[i >> 1] + 1;
    }
    for(int bit = 1; (1 << bit) <= sz; bit++) {
        for(i = 1; i + (1 << bit) <= sz + 1; i++) {
            int x = rmq[i][bit - 1], y = rmq[i + (1 << (bit - 1))][bit - 1];
            if(lvl[x] < lvl[y]) {
                rmq[i][bit] = x;
            }
            else {
                rmq[i][bit] = y;
            }
        }
    }
    int nr = nodes.size();
    for(i = 0; i < nr; i++) {
        for(j = 0; j < nr; j++) {
            if(mp[{nodes[i], nodes[j]}] == 0) {
                dp[1][i][j] = get_dist(nodes[i], nodes[j]);
            }
            else {
                dp[1][i][j] = min(1LL * mp[{nodes[i], nodes[j]}], get_dist(nodes[i], nodes[j]));
            }
        }
    }
    for(int k = 0; k < nr; k++) {
        for(i = 0; i < nr; i++) {
            for(j = 0; j < nr; j++) {
                dp[k & 1][i][j] = min(dp[1 - k & 1][i][j], dp[1 - k & 1][i][k] + dp[1 - k & 1][k][j]);
            }
        }
    }
    cin >> q;
    while(q > 0) {
        q--;
        int x, y;
        cin >> x >> y;
        ll ans = get_dist(x, y);
        for(i = 0; i < nr; i++) {
            for(j = 0; j < nr; j++) {
                ans = min(ans, get_dist(x, nodes[i]) + dp[1 - nr & 1][i][j] + get_dist(nodes[j], y));
            }
        }
        cout << ans << "\n";
    }
    //cin.close();
    //cout.close();
    return 0;
}