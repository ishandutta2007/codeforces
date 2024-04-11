#include <cstdio>
#include <memory.h>
#include <algorithm>

using namespace std;
const int N = 1e5 + 10;

int a[N], b[N], tree[N], p[N], s[N], res[N], ans[N], times[N];

int get(int x) {
    int res = 0;
    for (int i = x; i >= 0; i = (i & (i + 1)) - 1) res = max(res, tree[i]);
    return res;
}

void modify(int x, int value) {
    for (int i = x; i < N; i = (i | (i + 1))) tree[i] = max(tree[i], value);
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    memset(tree, 0, sizeof(tree));
    for (int i = 1; i <= n; i++) {
        p[i] = get(a[i] - 1) + 1;
        modify(a[i], p[i]);
    }
    memset(tree, 0, sizeof(tree));
    for (int i = n; i >= 1; i--) {
        s[i] = 1 + get(N - a[i] - 1);
        modify(N - a[i], s[i]);
    }
    memset(tree, 0, sizeof(tree));
    int ideal = 0;
    for (int i = 1; i <= n; i++) {
        res[i] = s[i] + get(a[i] - 1);
        ideal = max(ideal, res[i]);
        modify(a[i], p[i]);
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) if (res[i] != ideal) ans[i] = 1;
    else {
        cnt++;
        a[cnt] = a[i];
        b[cnt] = i;
    }
    memset(tree, 0, sizeof(tree));
    for (int i = 1; i <= cnt; i++) {
        res[i] = get(a[i] - 1) + 1;
        times[res[i]]++;
        modify(a[i], res[i]);
    }
    for (int i = 1; i <= cnt; i++) ans[b[i]] = (times[res[i]] != 1 ? 2 : 3);
    for (int i = 1; i <= n; i++) printf("%d", ans[i]);
    return 0;
}