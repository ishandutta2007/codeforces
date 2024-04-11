#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

#define int long long

int dx[] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};

int k, d, t;

signed main() {
    cin >> k >> d >> t;
    t *= 2;
    int cycle = k * 2 + (k % d == 0 ? 0 : (d - k % d));
    double ans = (t / cycle) * (k + (k % d == 0 ? 0 : (d - k % d)));
    if (t % cycle <= k * 2) {
        ans += t % cycle / 2.0;
    } else {
        ans += k;
        ans += t % cycle - k * 2;
    }
    printf("%f\n", ans);
    return 0;
}