#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;
const int N = 1e3 + 10;

int x[N], b[N], prev[N], n, l;
double g[N][N], f[N];

bool ok(double lim) {
    for (int i = 1; i <= n; i++) {
        f[i] = b[i] * lim - g[0][i];
        prev[i] = 0;
    }
    for (int i = 1; i <= n; i++) for (int j = 1; j < i; j++) {
        double value = b[i] * lim - g[j][i] + f[j];
        if (value <= f[i]) continue;
        f[i] = value;
        prev[i] = j;
    }
    return (f[n] >= 0);
}

int main() {
    scanf("%d %d", &n, &l);
    for (int i = 1; i <= n; i++) scanf("%d %d", &x[i], &b[i]);
    for (int i = 0; i <= n; i++) for (int j = i + 1; j <= n; j++) g[i][j] = sqrt(abs(x[j] - x[i] - l));
    double l = 0, r = 2e9;
    for (int i = 1; i <= 100; i++) {
        double m = (l + r) / 2;
        if (ok(m)) r = m; else l = m;
    }
    ok(r);
    vector <int> ans;
    ans.clear();
    for (int i = n; i != 0; i = prev[i]) ans.push_back(i);
    for (int i = ans.size() - 1; i >= 0; i--) printf("%d ", ans[i]);
    return 0;
}