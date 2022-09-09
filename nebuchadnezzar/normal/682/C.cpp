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
const int MAXN = 1e5 + 5;

int n;
int arr[MAXN];
vector<pii> graph[MAXN];
int ans = 0;

int dfs(int v, ll d, ll mi, bool up) {
    bool down = false;
    ll tmp = d - mi;
    if (tmp > arr[v] || up) {
        ans++;
        down = true;
    }
    for (auto p: graph[v]) {
        dfs(p.ff, d + p.ss, min(mi, d + p.ss), down);
    }
    return 0;
}

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n - 1; ++i) {
        int p, w;
        scanf("%d%d", &p, &w);
        graph[p - 1].puba({i + 1, w});
    }

    dfs(0, 0, 0, false);

    cout << ans << "\n";

    return 0;
}