#include <cstdio>
#include <vector>

using namespace std;
const int MOD = 1e9 + 7;
const int N = 2e3 + 10;

int a[N], d;
bool used[N][N];
vector <int> edges[N];

int dfs(int x, int prev, int basis) {
    if (a[x] < a[basis]) return 0;
    if (a[x] - a[basis] > d) return 0;
    if (a[x] == a[basis] && used[x][basis]) return 0;
    used[basis][x] = true;
    int ans = 1;
    for (int i = 0; i < edges[x].size(); i++) {
        int to = edges[x][i];
        if (to == prev) continue;
        ans = (1LL * ans * (dfs(to, x, basis) + 1)) % MOD;
    }
    return ans;
}

int main() {
    int n;
    scanf("%d %d", &d, &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i < n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) ans = (ans + dfs(i, i, i)) % MOD;
    printf("%d\n", ans);
    return 0;
}