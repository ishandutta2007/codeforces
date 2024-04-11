#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 100010;
const int INF = (int)1e9 + 10;

int n;
int a[N];

main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        int maxDiff = 0;
        int maxVal = -INF;
        for (int i = 1; i <= n; i++) {
            if (maxVal > a[i]) {
                maxDiff = max(maxDiff, maxVal - a[i]);
            }
            maxVal = max(maxVal, a[i]);
        }
        if (maxDiff == 0) cout << 0 << '\n';
        else {
            int res = 0;
            for (int i = 0; i < 31; i++) {
                if (maxDiff >> i & 1) res = max(res, i + 1);
            }
            cout << res << '\n';
        }
    }
    return 0;
}