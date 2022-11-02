#include <cstdio>

using namespace std;
const int N = 1e6 + 10;

int x[N], y[N], in[N], res[N], cnt[N];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &x[i], &y[i]);
        in[x[i]] = y[i];
        cnt[x[i]]++;
        cnt[y[i]]++;
    }
    int v = in[0];
    for (int i = 2; i <= n; i += 2, v = in[v]) res[i] = v;
    for (int i = 1; i <= n; i++) if (cnt[x[i]] == 1) v = x[i];
    for (int i = 1; i <= n; i += 2, v = in[v]) res[i] = v;
    for (int i = 1; i <= n; i++) printf("%d ", res[i]);
    return 0;
}