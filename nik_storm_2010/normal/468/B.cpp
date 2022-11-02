#include <cstdio>
#include <map>

using namespace std;
const int N = 2e5;

map <int, int> base, pos;
int x[N], n, a, b;

bool dfs(int now, int cnt) {
    if (cnt % 2 == 0 && base[now] == 1) {
        x[pos[now]] = -1;
        base[now] = 2;
        return true;
    }
    int go = (cnt % 2 == 0 ? a - now : b - now);
    if (base[go] == 0) return false;
    bool res = dfs(go, cnt + 1);
    if (!res) return false;
    x[pos[now]] = -1;
    base[now] = 2;
    return true;
}

int main() {
    scanf("%d %d %d", &n, &a, &b);
    for (int i = 1; i <= n; i++) scanf("%d", &x[i]);
    for (int i = 1; i <= n; i++) base[x[i]] = 1, pos[x[i]] = i;
    for (int i = 1; i <= n; i++) if (base[a - x[i]] == 1) base[a - x[i]] = 2, x[i] = 0;
    for (int i = 1; i <= n; i++) {
        if (x[i] <= 0) continue;
        bool ok = dfs(x[i], true);
        if (!ok) {
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    for (int i = 1; i <= n; i++) if (x[i] == 0) printf("0 "); else printf("1 ");
    return 0;
}