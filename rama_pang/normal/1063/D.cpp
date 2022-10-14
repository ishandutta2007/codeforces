#include <iostream>
using namespace std;
using lint = long long;

int main() {
    lint n, l, r, k, ans = -1;

    cin >> n >> l >> r >> k;
    lint x = (r + n - l + 1) % n;

    for (lint i = k, nxt; i > 0; i = nxt) {
        lint t = k / i;
        lint upper = i;
        lint lower = n;
        nxt = k / (t + 1);

        upper = min(upper, 2 * n);
        upper = min(upper, (k - x) / t);
        upper = min(upper, (2 * n - 2 * x + k + 1) / (t + 1));

        lower = max(lower, nxt + 1);
        lower = max(lower, (k - 2 * x + t - 1) / t);

        if (upper >= lower) {
            ans = max(ans, upper - n);
            break;
        }
    }

    if (x <= k && k < 2 * x) ans = max(ans, n - x + 1 + k - x);

    if (k == 2 * x) ans = max(ans, n);

    if (k == n) ans = max(ans, 1ll);

    cout << ans << "\n";

    return 0;
}