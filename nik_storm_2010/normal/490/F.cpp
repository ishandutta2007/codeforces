#include <cstdio>
#include <vector>

using namespace std;
const int N = 6000 + 10;
const int INF = 2000000000;

vector <int> edges[N];
int a[N], f[N], ans;

void dfs(int x, int pred) {
    int l = 0, r = N;
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (f[m] < a[x]) {
            l = m;
        } else {
            r = m;
        }
    }
    l++;
    int persist = f[l];
    f[l] = a[x];
    ans = max(ans, l);
    for (size_t i = 0; i < edges[x].size(); i++) {
        int to = edges[x][i];
        if (to == pred) {
            continue;
        }
        dfs(to, x);
    }
    f[l] = persist;
}

int main() {
    f[0] = 0;
    for (int i = 1; i < N; i++) {
        f[i] = INF;
    }
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i < n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    ans = 0;
    for (int i = 1; i <= n; i++) {
        dfs(i, i);
    }
    printf("%d\n", ans);
    return 0;
}