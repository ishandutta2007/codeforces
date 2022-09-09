#include "bits/stdc++.h"
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())
#define TASK_NAME ""

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MAXN = 2e5 + 5;

int n, k;
int is_city[MAXN];
vector<int> graph[MAXN];

ll d1[MAXN];
int d2[MAXN];
int maxhere[MAXN];

int dfs(int v, int p) {
    for (int to: graph[v]) {
        if (to != p) {
            dfs(to, v);
            d2[v] += d2[to];
            d1[v] += d1[to] + d2[to];
            maxhere[v] = max(maxhere[v], d2[to]);
        }
    }
    d2[v] += is_city[v];
    return 0;
}

ll ans[MAXN];

int dfs2(int v, int p, ll ud1, int ud2) {
    maxhere[v] = max(maxhere[v], ud2);
    ans[v] = d1[v] + ud1;
    for (int to: graph[v]) {
        if (to != p) {
            int nd2 = ud2 + d2[v] - d2[to];
            ll nd1 = ud1 + (d1[v] - d1[to] - d2[to]) + nd2;
            dfs2(to, v, nd1, nd2);
        }
    }
    return 0;
}

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);

    scanf("%d%d", &n, &k);

    for (int i = 0; i < 2 * k; ++i) {
        int num;
        scanf("%d", &num);
        --num;
        is_city[num] = 1;
    }

    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        --a; --b;
        graph[a].puba(b);
        graph[b].puba(a);
    }

    dfs(0, 0);
    dfs2(0, 0, 0, 0);

    int mem = -1;
    ll best = -1;
    for (int i = 0; i < n; ++i) {
        if (maxhere[i] <= k && best < ans[i]) {
            mem = i;
            best = ans[i];
        }
    }

    //cerr << mem << endl;
    cout << best << "\n";

    return 0;
}