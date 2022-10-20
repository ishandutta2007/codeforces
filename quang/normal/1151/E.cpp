#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n;
int a[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    a[0] = 0;
    long long res = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == a[i - 1]) continue;
        if (a[i] > a[i - 1]) {
            res += 1ll * (n - a[i] + 1) * (a[i] - a[i - 1]);
        } else {
            res += 1ll * a[i] * (a[i - 1] - a[i]);
        }
        // cout << i << ' ' << res << endl;
    }
    cout << res << endl;
    return 0;
}