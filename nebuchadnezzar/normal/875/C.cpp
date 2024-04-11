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

const int MAXN = 1e5 + 5;

vector<int> graph[MAXN], graph2[MAXN];
int res[MAXN];
bool used[MAXN];

int dfs(int v, vector<int>* g, int c) {
    used[v] = true;
    if (res[v] == 1 - c) {
        cout << "No\n";
        exit(0);
    }
    res[v] = c;
    for (int to : g[v]) {
        if (!used[to]) {
            dfs(to, g, c);
        }
    }
    return 0;
}

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);
    cerr << fixed << setprecision(15);
    cout << fixed << setprecision(15);
    
    int n, m;
    scanf("%d%d", &n, &m);

    vector<vector<int>> inp;
    for (int i = 0; i < n; ++i) {
        int l;
        scanf("%d", &l);

        inp.puba({});
        for (int j = 0; j < l; ++j) {
            int num;
            scanf("%d", &num);
            --num;
            inp.back().puba(num);
        }
    }

    for (int i = 0; i < m; ++i) {
        res[i] = 2;
    }

    for (int i = 0; i < n - 1; ++i) {
        bool flag = false;
        for (int j = 0; j < min(szof(inp[i]), szof(inp[i + 1])); ++j) {
            if (inp[i][j] != inp[i + 1][j]) {
                flag = true;
                if (inp[i][j] > inp[i + 1][j]) {
                    //cerr << inp[i][j] << " " << inp[i + 1][j] << endl;
                    if (res[inp[i][j]] == 1 || res[inp[i + 1][j]] == 0) {
                        cout << "No\n";
                        return 0;
                    }
                    res[inp[i][j]] = 0;
                    res[inp[i + 1][j]] = 1;
                } else {
                    graph[inp[i + 1][j]].puba(inp[i][j]);
                    graph2[inp[i][j]].puba(inp[i + 1][j]);
                }
                break;
            }
        }
        if (!flag && szof(inp[i]) > szof(inp[i + 1])) {
            cout << "No\n";
            return 0;
        }
    }
    
    /*
    for (int i = 0; i < m; ++i) {
        cerr << res[i];
    }
    cerr << endl;
    */

    for (int i = 0; i < m; ++i) {
        if (res[i] == 0 && !used[i]) {
            dfs(i, graph, res[i]);
        }
        if (res[i] == 1 && !used[i]) {
            dfs(i, graph2, res[i]);
        }
    }

    cout << "Yes\n";
    vector<int> ans;
    for (int i = 0; i < m; ++i) {
        if (res[i] == 0) {
            ans.puba(i);
        }
    }

    cout << szof(ans) << "\n";

    for (int num : ans) {
        cout << num + 1 << " ";
    }
    cout << "\n";

    
    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}