#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 10;
int n, m, s[N];
int x[N];
signed main() {
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", s + i);
        s[i] += s[i - 1];
    }
    for (int i = 1; i <= m; ++i) scanf("%lld", x + i);
    x[++m] = -1e9;
    x[++m] = 2e9;
    sort(x + 1, x + m + 1);
    int ans = 0;
    for (int i = 1, cur = 1; i < m; ++i) {
        while (cur <= n && (cur - 1) * 100 <= x[i]) ++cur;
        int la = cur - 1;
        while (la < n && la * 100 < x[i + 1]) ++la;
        // printf("%lld %lld %lld %lld\n", x[i], x[i + 1], cur, la);
        for (int j = cur; j <= la; ++j) {
            int hut_pos = (j - 1) * 100;
            int shop_pos = hut_pos * 2 - x[i];
            if (shop_pos >= x[i + 1]) {
                ans = max(ans, s[la] - s[j - 1]);
                break;
            } else {
                int mid = (shop_pos + x[i + 1] - 1) / 2;
                int t_la = min(mid / 100 + 1 , n);
                ans = max(ans, s[t_la] - s[j - 1]);
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}