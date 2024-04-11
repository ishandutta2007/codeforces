#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, d, e;
    cin >> n >> d >> e;
    int res = n;
    for (int i = 0; i <= n; i++) {
        if (1ll * i * 5 * e > n) break;
        int now = n - i * 5 * e;
        now /= d;
        int sum = i * 5 * e + now * d;
        res = min(res, n - sum);
    }
    cout << res << endl;
    return 0;
}