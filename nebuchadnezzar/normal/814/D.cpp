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
const int MAXN = 1005;

vector<int> graph[MAXN];
vector<pair<pii, int>> inp;
bool used[2][2][MAXN];
double d[2][2][MAXN];

bool inside(pair<pii, int> p1, pair<pii, int> p2) {
    if (p1.ss >= p2.ss) {
        return false;
    }
    return (ll) (p1.ff.ff - p2.ff.ff) * (p1.ff.ff - p2.ff.ff) + (ll) (p1.ff.ss - p2.ff.ss) * (p1.ff.ss - p2.ff.ss) < (ll) p2.ss * p2.ss;
}

double dfs(int v, vector<int> f) {
    if (used[f[0]][f[1]][v]) {
        return d[f[0]][f[1]][v];
    }
    
    used[f[0]][f[1]][v] = true;
    auto& val = d[f[0]][f[1]][v];
    //cerr << v << " " << f[0] << " " << f[1] << endl;
    val = -INFL;

    double tmp = PI * inp[v].ss * inp[v].ss;

    for (int i = 0; i < 2; ++i) {
        double res = 0;
        if (f[i] == 0) {
            res += tmp;
        } else {
            res -= tmp;
        }
        f[i] ^= 1;
        
        for (int to : graph[v]) {
            res += dfs(to, f);
        }
        f[i] ^= 1;
        val = max(val, res);
    }
    return val;
}

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);
    cerr << fixed << setprecision(15);
    cout << fixed << setprecision(15);
    
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        int x, y, r;
        scanf("%d%d%d", &x, &y, &r);
        inp.puba({{x, y}, r});
    }
    
    vector<int> roots;
    for (int i = 0; i < n; ++i) {
        int mem = -1;
        for (int j = 0; j < n; ++j) {
            if (i != j) {
                if (inside(inp[i], inp[j])) {
                    if (mem == -1 || inp[mem].ss > inp[j].ss) {
                        mem = j;
                    }
                }
            }
        }
        if (mem != -1) {
            //cerr << mem << " -> " << i << endl;
            graph[mem].puba(i);
        } else {
            roots.puba(i);
        }
    }
    
    double ans = 0;
    for (int i : roots) {
        ans += dfs(i, {0, 0});
    }

    cout << ans << "\n";

    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}