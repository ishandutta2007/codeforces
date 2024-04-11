#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;
typedef vector <int> vi;

#define rep(i, n) for(int i = 0; i < (n); ++i)

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(c) c.begin(), c.end()
#define mset(a, v) memset(a, v, sizeof(a))
#define sz(a) ((int)a.size())

#define dbn cerr << "\n"
#define dbg(x) cerr << #x << " : " << (x) << " "
#define dbs(x) cerr << (x) << " "

const int N = 200200;

vi adj[N];
int pinkCount[N];
int col[N];

void dfs(int u, int par = -1) {
    pinkCount[u] = col[u] == -1;
    rep (i, sz(adj[u])) {
        int v = adj[u][i];
        if (v != par) {
            dfs(v, u);
            pinkCount[u] += pinkCount[v];
        }
    }
    // dbg(u), dbg(pinkCount[u]), dbn;
}

void solve(int u, int par = -1) {
    rep (i, sz(adj[u])) {
        int v = adj[u][i];
        // dbg(u), dbg(v), dbg(pinkCount[v]), dbn;
        if (v == par or pinkCount[v] == 0) {
            continue;
        }
        printf("%d ", v + 1);
        col[v] *= -1;
        solve(v, u);
        printf("%d ", u + 1);
        col[u] *= -1;
    }
    if (col[u] == -1 and par != -1) {
        col[par] *= -1;
        col[u] *= -1;
        printf("%d %d ", par + 1, u + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
        
    int n;
    cin >> n;

    rep (i, n) {
        cin >> col[i];
    }

    rep (i, n - 1) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    dfs(0);
    printf("1 ");
    solve(0);
    if (col[0] == -1) {
        int u = adj[0][0] + 1;
        printf("%d %d %d", u, 1, u);
    }
    puts("");

    return 0;
}