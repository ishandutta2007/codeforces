#include<cstdio>
#include<algorithm>
#include<cmath>

using namespace std;
typedef long long ll;
const int N = (1 << 19);
const int P = 19;

int close[N], size1, size2;
ll q1[N], q2[N], m1[N], m2[N], old[N], f[N];

void from() {
    if (size1 == 0) {
        for (int i = size2; i > 0; i--) {
            size1++;
            q1[size1] = q2[i];
            m1[size1] = max(m1[size1 - 1], q1[size1]);
        }
        size2 = 0;
    }
    size1--;
}

void add(int x) {
    size2++;
    q2[size2] = old[x];
    m2[size2] = max(m2[size2 - 1], q2[size2]);
}

int main() {
    m1[0] = -1e18;
    m2[0] = -1e18;
    int n, m, d;
    scanf("%d %d %d", &n, &m, &d);
    int prev = 0;
    for (int i = 0; i < m; i++) {
        int a, b, t;
        int ll = 1, rr = 0;
        size1 = size2 = 0;
        scanf("%d %d %d", &a, &b, &t);
        for (int j = 1; j <= n; j++) {
            int cost = b - abs(a - j);
            int left = max(1LL, j - 1LL * (t - prev) * d);
            int right = min(0LL + n, j + 1LL * (t - prev) * d);
            while (right != rr) rr++, add(rr);
            while (left != ll) from(), ll++;
            f[j] = max(m1[size1], m2[size2]) + cost;
        }
        for (int j = 1; j <= n; j++) old[j] = f[j];
        prev = t;
    }
    ll ans = -1e18;
    for (int i = 1; i <= n; i++) ans = max(ans, old[i]);
    printf("%I64d\n", ans);
    return 0;
}