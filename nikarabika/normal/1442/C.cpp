//sobskdrbhvk
//remember...
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

const int maxn = 200 * 1000 + 10,
      maxl = 20;
const LL Mod = 998244353;
int base[2][maxn],
    dis[maxn][2][maxl];
bool bmark[2][maxn],
     mark[maxn][2][maxl];
int n, m;
vector<int> adj[2][maxn];

void bfs0() {
    memset(base, 63, sizeof base);
    deque<pii> q;
    q.PB(MP(0, 0));
    base[0][0] = 0;
    while (sz(q)) {
        pii u = q.front();
        q.pop_front();
        if (bmark[u.L][u.R]) continue;
        bmark[u.L][u.R] = true;
        for (int v: adj[u.L][u.R]) {
            if (base[u.L][u.R] < base[u.L][v]) {
                base[u.L][v] = base[u.L][u.R];
                q.push_front(MP(u.L, v));
            }
        }
        if (base[u.L][u.R] + 1 < base[!u.L][u.R]) {
            base[!u.L][u.R] = base[u.L][u.R] + 1;
            q.PB(MP(!u.L, u.R));
        }
    }
}

void bfs1() {
    memset(dis, 63, sizeof dis);
    deque<piii> q;

    dis[0][0][0] = 0;
    q.PB(MP(0, MP(0, 0)));
    while (sz(q)) {
        auto obj = q.front();
        q.pop_front();
        int u = obj.L,
            prt = obj.R.L,
            bst = obj.R.R;
        if (mark[u][prt][bst]) continue;
        mark[u][prt][bst] = true;

        int nprt = !prt;
        int nbst = bst + base[prt][u] - base[nprt][u] + 1;
        if (nbst >= 0 and nbst < maxl and dis[u][prt][bst] < dis[u][nprt][nbst]) {
            dis[u][nprt][nbst] = dis[u][prt][bst];
            q.push_front(piii(u, pii(nprt, nbst)));
        }

        for (auto v: adj[prt][u]) {
            nbst = bst + base[prt][u] - base[prt][v];
            if (nbst < maxl and dis[u][prt][bst] + 1 < dis[v][prt][nbst]) {
                dis[v][prt][nbst] = dis[u][prt][bst] + 1;
                q.PB(piii(v, pii(prt, nbst)));
            }
        }
        
    }
}

pii mymin(pii x, pii y) {
    if (x < y)
        swap(x, y);
    if (x.L > 30 or x.L == y.L)
        return y;
    LL numy = ((1LL << (y.L))) + y.R;
    LL numx = ((1LL << (x.L))) + x.R;
    return numx < numy ? x : y;
}

int solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int fi, se;
        cin >> fi >> se;
        fi--, se--;
        adj[0][fi].PB(se);
        adj[1][se].PB(fi);
    }
    bfs0();
    bfs1();
    pii ans(2 * maxn, 2 * maxn);
    for (int prt = 0; prt < 2; prt++, cerr << '\n')
        for (int bst = 0; bst < maxl; bst++) {
            cerr << bst + base[prt][n - 1] << '/' << dis[n - 1][prt][bst] << ' ';
            ans = mymin(ans, pii(base[prt][n - 1] + bst, dis[n - 1][prt][bst]));
        }
    LL num = 1;
    for (int i = 0; i < ans.L; i++)
        num = num * 2 % Mod;
    num += ans.R + Mod - 1;
    num %= Mod;
    cerr << ans.L << ' ' << ans.R << '\n';
    cout << num << '\n';
    return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int q = 1;
	while (q--)
		solve();
	return 0;
}