#include <cstdio>
#include <set>

using namespace std;
const int N = 2e5 + 10;
const int MAX = 1e6 + 10;

int a[N], next[2 * MAX];
set <int> all;
bool used[MAX];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        if (all.find(-a[i]) != all.end()) continue;
        all.insert(-a[i]);
    }
    for (int i = 1; i < 2 * MAX; i++) {
        set <int>::iterator it = all.upper_bound(-i);
        next[i] = -(*it);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (used[a[i]]) continue;
        used[a[i]] = true;
        if (ans >= a[i]) continue;
        for (int x = 2 * a[i]; x <= MAX + a[i]; x += a[i]) ans = max(ans, next[x] % a[i]);
    }
    printf("%d\n", ans);
    return 0;
}