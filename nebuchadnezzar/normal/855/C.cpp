#include "bits/stdc++.h"
#define puba push_back
#define ff first
#define ss second
#define bend(_x) begin(_x), end(_x)
#define szof(_x) ((int) (_x).size())
#define TASK_NAME ""

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9 + 7;
const ll INFL = 1e18 + 123;
const double PI = atan2(0, -1);
mt19937 tw(960172);
ll rnd(ll x, ll y) { static uniform_int_distribution<ll> d; return d(tw) % (y - x + 1) + x; }

const int MAXN = 1e5 + 5, MAXX = 13, MOD = 1e9 + 7;

int k, x;
int n, m;
vector<int> graph[MAXN];
int d[3][MAXX][MAXN];
int tmpd[3][MAXX];  

void add(int& a, int b) {
    a += b;
    if (a >= MOD) {
        a -= MOD;
    }
}

int dfs(int v, int p) {
    d[0][0][v] = k - 1;
    d[1][1][v] = 1;
    d[2][0][v] = m - k;

    for (int to : graph[v]) {
        if (p != to) {
            dfs(to, v);
            memset(tmpd, 0, sizeof tmpd);
            for (int i = 0; i <= x; ++i) {
                for (int j = 0; j + i <= x; ++j) {
                    add(tmpd[0][i + j], (ll) d[0][i][v] * ((ll) d[0][j][to] + d[1][j][to] + d[2][j][to]) % MOD);
                    add(tmpd[1][i + j], (ll) d[1][i][v] * d[0][j][to] % MOD);
                    add(tmpd[2][i + j], (ll) d[2][i][v] * ((ll) d[0][j][to] + d[2][j][to]) % MOD);
                }
            }
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j <= x; ++j) {
                    d[i][j][v] = tmpd[i][j];
                }
            }
        }
    }
    /*
    cerr << v << endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j <= x; ++j) {
            cerr << d[i][j][v] << " ";
        }
        cerr << endl;
    }
    */
    return 0;
}

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);
    cerr << fixed << setprecision(15);
    cout << fixed << setprecision(15);
    
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        --a; --b;
        graph[a].puba(b);
        graph[b].puba(a);
    }
    
    
    scanf("%d%d", &k, &x);

    dfs(0, 0);

    int ans = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j <= x; ++j) {
            add(ans, d[i][j][0]);
        }
    }

    cout << ans % MOD << "\n";
    
    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}