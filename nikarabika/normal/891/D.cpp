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

const int maxn = 500 * 1000 + 10;
int par[maxn],
    dp[maxn][2][2],
    up[maxn],
    siz[maxn],
    down[maxn],
    odds[maxn],
    bothmost[maxn],
    bothflip[maxn],
    peek[maxn],
    parflip[maxn],
    parflip_sibl[maxn],
    oddable[maxn],
    upgood[maxn],
    n;
vector<int> adj[maxn],
    vert;

void dfs(int u, int p = -1) {
    vert.PB(u);
    par[u] = p;
    for (int v: adj[u])
        if (v != p)
            dfs(v, u);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i < n; i++) {
        int fi, se;
        cin >> fi >> se;
        fi--, se--;
        adj[fi].PB(se);
        adj[se].PB(fi);
    }
    if (n % 2)
        return cout << 0 << endl, 0;
    dfs(0);
    for (int i = n - 1; i >= 0; i--) {
        int u = vert[i];
        siz[u]++;
        if (i) siz[par[u]] += siz[u];
    }
//    cerr << "Size: ";
//    for (int i = 0; i < n; i++)
//        cerr << siz[i] << ' ';
//    cerr << '\n';
    for (int u = 0; u < n; u++) {
        sort(all(adj[u]), [](int i, int j) -> bool { return siz[i] < siz[j]; });
        if (u) adj[u].pop_back();
    }
    for (int i = n - 1; i >= 0; i--) {
        int u = vert[i];
        dp[u][0][siz[u] & 1 ^ 1] = 0;
        dp[u][1][siz[u] & 1] = 0;
        dp[u][0][siz[u] & 1] = 1;
        int odds = siz[u] & 1;
        int valids = 0;
        for (auto v: adj[u]) {
            valids += dp[v][0][siz[v] & 1];
            odds += siz[v] & 1;
        }
        dp[u][0][siz[u] & 1] = (odds < 2) and (valids == sz(adj[u]));
        ::odds[u] = odds;
        odds -= siz[u] & 1;
        if (odds > 3 or valids + 1 < sz(adj[u]))
            dp[u][1][siz[u] & 1 ^ 1] = 0;
        else {
            for (auto v: adj[u])
                if (odds - (siz[v] & 1) + (siz[v] & 1 ^ 1) + (siz[u] & 1 ^ 1) <= 1 and valids + (!dp[v][0][siz[v] & 1]) >= sz(adj[u]))
                    dp[u][1][siz[u] & 1 ^ 1] += dp[v][1][siz[v] & 1 ^ 1];
            if (valids == sz(adj[u]) and odds == 0 and siz[u] % 2 == 1)
                dp[u][1][siz[u] & 1 ^ 1]++;
        }
        down[u] = dp[u][0][siz[u] & 1];
    }
//    cerr << "DP:\n";
//    for (int u = 0; u < n; u++) {
//        cerr << u << ":\n";
//        for (int i = 0; i < 2; i++, cerr << '\n') {
//            cerr << "    ";
//            for (int j = 0; j < 2; j++)
//                cerr << dp[u][i][j] << ' ';
//        }
//    }
//    cerr << "Down: ";
//    for (int i = 0; i < n; i++)
//        cerr << down[i] << ' ';
//    cerr << '\n';
    for (int i = 0; i < n; i++) {
        int u = vert[i];
        if (i == 0)
            up[u] = true;
        bool amigood = odds[u] <= 1;
        int vgoods = 0;
        for (auto v: adj[u])
            vgoods += down[v];

        vector<int> le[2][2];
        for (int i = 0; i < 4; i++)
            le[i / 2][i & 1].PB(i == 0);
        for (auto v: adj[u]) {
            up[v] = up[u] and amigood and (vgoods - down[v] + 1 == sz(adj[u]));

            int nodds = odds[u]
                - (siz[u] & 1) + (siz[u] & 1 ^ 1)
                - (siz[v] & 1) + (siz[v] & 1 ^ 1);
            bothflip[v] = (nodds <= 1)
                and (vgoods - down[v] + 1 == sz(adj[u]));

            nodds = odds[u] - (siz[u] & 1) + (siz[u] & 1 ^ 1);
            parflip[v] = (nodds <= 1)
                and (vgoods - down[v] + 1 == sz(adj[u]));
            parflip_sibl[v] = (nodds - (siz[v] & 1) <= 1)
                and (vgoods - down[v] + 1 == sz(adj[u]));

            int tmp[2][2] = {0};
            for (int x = 0; x < 2; x++)
                for (int y = 0; y < 2; y++)
                    for (int xx = 0; xx <= x; xx++)
                        for (int yy = 0; yy <= y; yy++)
                            tmp[x][y] += le[xx][yy].back() * dp[v][x - xx][y - yy];
            for (int x = 0; x < 2; x++)
                for (int y = 0; y < 2; y++)
                    le[x][y].PB(tmp[x][y]);
        }
        int ri[2][2] = {0};
        ri[0][0] = 1;
        for (int j = sz(adj[u]) - 1; j >= 0; j--) {
            int v = adj[u][j];
            int ucol = siz[u] & 1,
                nvcol = siz[v] & 1 ^ 1;
            if (ucol ^ nvcol)
                peek[v] = le[0][0][j] * ri[1][0] + le[1][0][j] * ri[0][0];
            else if (!ucol and !nvcol) {
                peek[v] = le[0][0][j] * (ri[1][0] + ri[1][1])
                    + le[0][1][j] * ri[1][0]
                    + le[1][0][j] * (ri[0][0] + ri[0][1])
                    + le[1][1][j] * ri[0][0]
                    + le[0][0][j] * ri[0][0];
            }
            else
                peek[v] = 0;
            int tmp[2][2] = {0};
            for (int x = 0; x < 2; x++)
                for (int y = 0; y < 2; y++)
                    for (int xx = 0; xx <= x; xx++)
                        for (int yy = 0; yy <= y; yy++)
                            tmp[x][y] += ri[xx][yy] * dp[v][x - xx][y - yy];
            memcpy(ri, tmp, sizeof ri);
        }
    }

//    cerr << "Up: ";
//    for (int i = 0; i < n; i++)
//        cerr << up[i] << ' ';
//    cerr << '\n';
//
//    cerr << "Both flip: ";
//    for (int i = 0; i < n; i++)
//        cerr << bothflip[i] << ' ';
//    cerr << '\n';
//
//    cerr << "Par flip: ";
//    for (int i = 0; i < n; i++)
//        cerr << parflip[i] << ' ';
//    cerr << '\n';
//
//    cerr << "Par flip(selfless): ";
//    for (int i = 0; i < n; i++)
//        cerr << parflip_sibl[i] << ' ';
//    cerr << '\n';
//
//    cerr << "Peek: ";
//    for (int i = 0; i < n; i++)
//        cerr << peek[i] << ' ';
//    cerr << '\n';

    for (int i = 1; i < n; i++) {
        int u = vert[i];
        bothmost[u] = bothflip[u] ? bothmost[par[u]] : u;
        bool subtree_ok = true;
        for (auto v: adj[u])
            subtree_ok &= dp[v][0][0];

        if (!subtree_ok) continue;
        oddable[u]++;
        oddable[par[u]]--;

        if (!parflip_sibl[u]) continue;
        oddable[par[u]]++;
        if (bothmost[par[u]])
            oddable[par[bothmost[par[u]]]]--;
    }

//    cerr << "Bothmost: ";
//    for (int i = 0; i < n; i++)
//        cerr << bothmost[i] << ' ';
//    cerr << '\n';
//
//    cerr << "Odbl: ";
//    for (int i = 0; i < n; i++)
//        cerr << oddable[i] << ' ';
//    cerr << '\n';

    for (int i = n - 1; i >= 0; i--) {
        int u = vert[i];
        if (u) oddable[par[u]] += oddable[u];
    }

//    cerr << "Odbl: ";
//    for (int i = 0; i < n; i++)
//        cerr << oddable[i] << ' ';
//    cerr << '\n';

    LL ans = 0;
    for (int i = 0; i < n; i++) {
        int u = vert[i];
        int p = par[u];
        if (bothflip[u]) {
            upgood[u] = upgood[p];
            if (p) upgood[u] += up[par[p]] * peek[p];
        }
        else
            upgood[u] = 0;

        if (siz[u] % 2 == 0 and dp[0][0][0])
            ans += 1LL * siz[u] * (n - siz[u]);
        else if (siz[u] % 2 == 1) {
            ans += 1LL * oddable[u] * up[p] * peek[u];
            ans += 1LL * oddable[u] * upgood[u];
        }
    }

//    cerr << "Upgood: ";
//    for (int i = 0; i < n; i++)
//        cerr << upgood[i] << ' ';
//    cerr << '\n';

    cout << ans << '\n';
	return 0;
}