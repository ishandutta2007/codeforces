#include <bits/stdc++.h>

using namespace std;
int a[100005];
int main() {
#ifdef LDT
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int L = 1e9, R = -1e9;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        for (int i = 1; i <= n; ++i) if (a[i] != -1) {
            if (a[i - 1] == -1 || a[i + 1] == -1)
                L = min(L, a[i]), R = max(R, a[i]);
        }
        int k = -1;
        if (L > R) {
            k = 0;
        }
        else 
            k = (L + R) / 2;
        int res = 0;
        for (int i = 1; i <= n; ++i) if (a[i] == -1) a[i] = k;
        for (int i = 1; i <= n - 1; ++i)
            res = max(res, abs(a[i] - a[i + 1]));
        cout << res << ' ' << k << '\n';
    }
    return 0;
}