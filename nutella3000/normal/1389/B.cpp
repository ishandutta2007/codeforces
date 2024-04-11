#include <bits/stdc++.h>
using namespace std;
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
 
//#define int long long
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
        int n, k, z;
        cin >> n >> k >> z;

        vector<int> a(n), pref(n);
        for(int i = 0;i < n;i++) {
            cin >> a[i];
            pref[i] = a[i];
            if (i != 0) pref[i] += pref[i - 1];
        }

        int res = 0;

        int Max = 0;

        for(int i = 1;i < n;i++) {
            if (i > k) break;
            
            Max = max(Max, a[i - 1] + a[i]);

            int new_res = pref[i];
            int q = k - i;

            new_res += min(q / 2, z) * Max;
            if (q / 2 < z && q % 2 == 1) new_res += a[i - 1];

            res = max(res, new_res);
        }

        cout << res << endl;
    }
}