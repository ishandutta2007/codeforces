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
const int MAXN = 3e5 + 5;

vector<int> graph[MAXN];
int sz[MAXN];
set<vector<int>> arr[MAXN];
pii best[MAXN];
int ans[MAXN];

int dfs(int v, int p) {
    //cerr << v << " " << p << endl;
    sz[v] = 1;
    int biggest = 0;
    best[v] = {-1, -1};
    for (auto to: graph[v]) {
        if (to != p) {
            dfs(to, v);
            sz[v] += sz[to];
            biggest = max(biggest, sz[to]);
            best[v] = max(best[v], best[to]);
            if (szof(arr[to]) > szof(arr[v])) {
                swap(arr[to], arr[v]);
            }
            for (auto el: arr[to]) {
                arr[v].insert(el);
            }
        }
    }
    arr[v].insert({biggest, sz[v], v});

    while (szof(arr[v]) && (*arr[v].begin())[0] * 2 <= sz[v]) {
        best[v] = max(best[v], {(*arr[v].begin())[1], (*arr[v].begin())[2]});
        arr[v].erase(arr[v].begin());
    }

    ans[v] = best[v].ss;
    
    return 0;
}

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);

    int n, q;
    scanf("%d%d", &n, &q);

    for (int i = 0; i < n - 1; ++i) {
        int v;
        scanf("%d", &v);
        --v;
        graph[v].puba(i + 1);
    }

    dfs(0, 0);

    for (int i = 0; i < q; ++i) {
        int v;
        scanf("%d", &v);
        --v;
        cout << ans[v] + 1 << "\n";
    }

    return 0;
}