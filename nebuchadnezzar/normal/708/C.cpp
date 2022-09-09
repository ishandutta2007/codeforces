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
const int MAXN = 4e5 + 5;

int n, k;
vector<int> graph[MAXN];
int sz[MAXN];
int who[MAXN];
int larg[MAXN];
int ans[MAXN];

int dfs1(int v, int p) {
    sz[v] = 1;
    who[v] = -1;
    larg[v] = 0;
    for (int to: graph[v]) {
        if (to != p) {
            dfs1(to, v);
            sz[v] += sz[to];
            if (who[v] == -1 || sz[who[v]] < sz[to]) {
                who[v] = to;
            }
            if (sz[to] <= k) {
                larg[v] = max(larg[v], sz[to]);
            }
            larg[v] = max(larg[v], larg[to]);
        }
    }
    return 0;
}

int dfs2(int v, int p, int szu, int largu) {
    //cerr << v << " " << szu << " " << largu << endl;
    if (who[v] == -1 || sz[who[v]] <= k) {
        if (szu <= k || szu - largu <= k) {
            ans[v] = 1;
        } else {
            ans[v] = 0;
        }
    } else {
        if (sz[who[v]] - larg[who[v]] <= k) {
            ans[v] = 1;
        } else {
            ans[v] = 0;
        }
    }
    if (szu <= k) {
        largu = max(largu, szu);
    }
    vector<int> suff;
    for (int to: graph[v]) {
        if (to != p) {
            suff.puba(larg[to]);
            if (sz[to] <= k) {
                suff.back() = max(suff.back(), sz[to]);
            }
        }
    }
    suff.puba(0);
    for (int i = szof(suff) - 2; i >= 0; --i) {
        suff[i] = max(suff[i], suff[i + 1]);
    }
    int c = 0;
    for (int to: graph[v]) {
        if (to != p) {
            dfs2(to, v, n - sz[to], max(largu, suff[c + 1]));
            largu = max(largu, larg[to]);
            if (sz[to] <= k) {
                largu = max(largu, sz[to]);
            }
            ++c;
        }
    }
    return 0;
}

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);

    scanf("%d", &n);
    k = n / 2;

    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        --a; --b;
        graph[a].puba(b);
        graph[b].puba(a);
    }

    dfs1(0, 0);

    /*
    for (int i = 0; i < n; ++i) {
        cout << sz[i] << " " << who[i] << " " << larg[i] << endl;
    }*/

    dfs2(0, 0, 0, 0);

    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
    cout << "\n";

    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}