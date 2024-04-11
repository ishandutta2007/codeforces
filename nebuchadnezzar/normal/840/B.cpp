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
const int MAXN = 3e5 + 5;

int d[MAXN];
vector<pii> graph[MAXN];
bool used[MAXN];
bool flag = false;
int in_ans[MAXN];
int edge[MAXN];

int dfs(int v, int ne) {
    edge[v] = ne;
    in_ans[v] ^= flag;
    used[v] = true;
    if (d[v] == 1) {
        flag ^= 1;
    }

    for (auto to : graph[v]) {
        if (!used[to.ff]) {
            dfs(to.ff, to.ss);
        }
    }

    in_ans[v] ^= flag;
    return 0;
}

int dfs2(int v) {
    if (d[v] == -1) {
        in_ans[v] ^= 1;
        return 1;
    }
    used[v] = true;
    for (auto to : graph[v]) {
        if (!used[to.ff]) {
            if (dfs2(to.ff)) {
                in_ans[v] ^= 1;
                return 1;
            }
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

    for (int i = 0; i < n; ++i) {
        scanf("%d", d + i);
    }

    for (int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        --a; --b;
        graph[a].puba({b, i});
        graph[b].puba({a, i});
    }

    dfs(0, -1);
    if (flag) {
        memset(used, 0, sizeof used);
        if (!dfs2(0)) {
            cout << "-1\n";
            return 0;
        }
    }
    
    vector<int> ans;

    for (int i = 0; i < n; ++i) {
        if (in_ans[i]) {
            ans.puba(edge[i]);
        }
    }

    cout << szof(ans) << "\n";

    for (int num : ans) {
        cout << num + 1 << "\n";
    }
    cout << "\n";

    
    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}