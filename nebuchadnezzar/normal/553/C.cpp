#include "bits/stdc++.h"
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;
typedef long long ll;
typedef double dbl;
typedef pair <int, int> pii;
const int MAXN = 1e5 + 5;
const ll MOD = 1e9 + 7;

int n, m;
vector <pii > graph[MAXN];
bool used[MAXN];
int nowl[MAXN];

int dfs(int v, int l) {
    used[v] = true;
    nowl[v] = l;
    for (int i = 0; i < szof(graph[v]); ++i) {
        if (!used[graph[v][i].ff]) {
            dfs(graph[v][i].ff, l + graph[v][i].ss);
        } else {
            if ((l + nowl[graph[v][i].ff] + graph[v][i].ss) & 1) {
                cout << 0 << endl;
                exit(0);
            }
        }
    }
    return 0;
}

int main() {    
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        --a;--b;
        c = 1 - c;
        graph[a].puba(mapa(b, c));
        graph[b].puba(mapa(a, c));
    }

    int numc = 0;
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            dfs(i, 0);
            ++numc;
        }
    }

    ll ans = 1;
    for (int i = 0; i < numc - 1; ++i) {
        ans = (ans * 2) % MOD;
    }

    cout << ans << endl;

    return 0;
}