#include <bits/stdc++.h>
#define pii pair<long long, long long>
#define int long long
using namespace std;
const int maxn = 1e6 + 10;
const double eps = 1e-10;
int a[maxn];
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        for(int i = 0; i < n; i++) cin >> a[i];
        if(n == 1) {
            cout << 0 << endl;
            continue;
        }
        int ans = n-2;
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                double d = (double)(a[j]-a[i])/(j-i), a0 = a[i] - i*d;
                int res = n;
                for(int k = 0; k < n; k++) {
                    if(abs(a[k]-a0-k*d) < eps) res--;
                }
                ans = min(ans, res);
            }
        }
        cout << ans << endl;
    }
    return 0;
}