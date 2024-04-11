#include <bits/stdc++.h>
using namespace std;
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
 
#define int long long
#define pii pair<int, int>
#define sz(a) ((int)a.size())
typedef long double ld;
const int inf = 1e9 + 7;
 
signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
 
    int t;
    cin >> t;
    while(t--) {
        int n, k, l1, r1, l2, r2;
        cin >> n >> k >> l1 >> r1 >> l2 >> r2;
 
        int k1 = max(0ll, max(l1, l2) - min(r1, r2));
        int k2 = max(r1, r2) - min(l1, l2);
 
        int per = max(0ll, min(r1, r2) - max(l1, l2));
 
        k2 -= per;
 
        k -= per * n;
 
        if (k < 0) {
            cout << 0 << endl;
            continue;
        }
 
        int res = 0;
 
 
        if (min(k, k2) > k1) {
            int q = k / k2;
 
            res += (k1 + k2) * min(q, n);
 
            k -= min(q, n) * k2;
 
            if (k >= k1 && q < n) {
                res += k1 + k;
                k = 0;
            }
 
        }else {
            res += k1 + min(k, k2);
            k -= min(k, k2);
        }
 
        res += k * 2;
 
        cout << res << endl;
 
    }
}