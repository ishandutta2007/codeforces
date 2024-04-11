#include "bits/stdc++.h"
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())

using namespace std;
typedef long long ll;
typedef double dbl;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;
const int MAXN = 1e5 + 5, bd = 18, MAXM = 1e6 + 5;
const ll MOD = 1e9 + 7;

int n, k;
vector <pii> graph[MAXN];
bool used[MAXN];
int binup[bd][MAXN];
int bdarr[bd];
int depth[MAXN];

int dfs(int v, int p, int d) {
    depth[v] = d;
    used[v] = true;
    binup[0][v] = p;
    for (int i = 1; i < bd; ++i) {
        binup[i][v] = binup[i - 1][binup[i - 1][v]];
    }
    for (int i = 0; i < szof(graph[v]); ++i) {
        if (!used[graph[v][i].ff]) {
            dfs(graph[v][i].ff, v, d + 1);
        }
    }
    return 0;
}

int calc_lca(int a, int b) {
    if (depth[a] > depth[b]) {
        swap(a, b);
    }
    //cerr << depth[a] << " " << depth[b] << endl;
    for (int i = bd - 1; i >= 0; --i) {
        if (depth[a] <= depth[b] - bdarr[i]) {
            b = binup[i][b];
        }
    }
    //cerr << depth[a] << " " << depth[b] << endl;
    //cerr << a << " " << b << endl;
    if (a == b) {
        return a;
    }
    for (int i = bd - 1; i >= 0; --i) {
        if (binup[i][a] != binup[i][b]) {
            a = binup[i][a];
            b = binup[i][b];
        }
    }
    return binup[0][a];
}

int from[MAXN];
int end_here[MAXN];

ll ans = 0;
ll costs[MAXM], costs2[MAXM];

int dfs2(int v) {
    int num_paths = 0;
    used[v] = true;
    for (int i = 0; i < szof(graph[v]); ++i) {
        if (!used[graph[v][i].ff]) {
            int tmp = dfs2(graph[v][i].ff);
            //cerr << v << " " << graph[v][i].ff << " " << graph[v][i].ss << " " << tmp << endl;
            if (graph[v][i].ss == -1) {
                ans = (ans + costs2[(tmp + 1) / 2]) % MOD;
            }
            if (graph[v][i].ss == 1) {
                ans = (ans + costs2[tmp / 2]) % MOD;
            }
            num_paths += tmp;
        }
    }
    num_paths -= end_here[v];
    num_paths += from[v];
    return num_paths;
}

int main() {    
    bdarr[0] = 1;
    for (int i = 1; i < bd; ++i) {
        bdarr[i] = bdarr[i - 1] * 2;
    }
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    scanf("%d", &n);

    for (int i = 0; i < n - 1; ++i) {
        int a, b, c;
        //cin >> a >> b >> c;
        scanf("%d%d%d", &a, &b, &c);
        --a;--b;
        graph[a].puba(mapa(b, c));
        graph[b].puba(mapa(a, -c));
    }

    dfs(0, 0, 0);

    //cin >> k;
    scanf("%d", &k);

    int prev = 0;
    for (int i = 0; i < k; ++i) {
        int now;
        //cin >> now;
        scanf("%d", &now);
        --now;
        int lca = calc_lca(prev, now);
        //cerr << prev << " " << now << " " << lca << endl;
        if (prev != lca) {
            //from[prev].puba(lca);
            ++from[prev];
            end_here[lca]++;
        }          
        if (now != lca) {
            //from[now].puba(lca);
            ++from[now];
            end_here[lca]++;
        }
        prev = now;
    }
    
    costs[0] = 1;

    for (int i = 1; i < MAXM; ++i) {
        costs[i] = (costs[i - 1] * 2) % MOD;
    }

    costs2[0] = 0;

    for (int i = 1; i < MAXM; ++i) {
        costs2[i] = (costs2[i - 1] + costs[i - 1]) % MOD;
    }

    memset(used, 0, sizeof used);
    dfs2(0);

    cout << ans << endl;

    return 0;
}