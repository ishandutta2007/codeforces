#include <cstdio>
#include <vector>

using namespace std;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;

vector <int> edges[N];
int f[N][2], color[N];

void solve(int x, int prev) {
    f[x][color[x]] = 1;
    for (int i = 0; i < edges[x].size(); i++) {
        int to = edges[x][i];
        if (to == prev) continue;
        solve(to, x);
        if (color[x] == 0) f[x][1] = (1LL * f[to][1] * f[x][0] + 1LL * f[x][1] * (f[to][0] + f[to][1])) % MOD;
        f[x][color[x]] = (1LL * f[x][color[x]] * (f[to][0] + f[to][1])) % MOD;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int x;
        scanf("%d", &x);
        edges[x].push_back(i);
        edges[i].push_back(x);
    }
    for (int i = 0; i < n; i++) scanf("%d", &color[i]);
    solve(0, 0);
    printf("%d\n", f[0][1]);
    return 0;
}