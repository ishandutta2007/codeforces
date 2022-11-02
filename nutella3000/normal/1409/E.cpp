#include <bits/stdc++.h>
using namespace std;
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
 
#define int long long
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pii pair<int, int>
#define mp make_pair
#define all(_v) _v.begin(), _v.end()
#define what_is(x) cout << #x << " is " << x << endl;
typedef long double ld;
 
const int inf = 1e10;



signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);

    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<int> x(n), y(n), dp(n);

        for(int i = 0;i < n;i++) 
            cin >> x[i];
        for(int i = 0;i < n;i++)
            cin >> y[i];

        sort(all(x));

        int res = 0;
        for(int i = 0;i < n;i++) {
            int l = -1;
            int r = i;
            while(r - l > 1) {
                int mid = (l + r) / 2;
                if (x[mid] + k >= x[i]) r = mid;
                else l = mid;
            }
            dp[i] = max((i == 0 ? 0 : dp[i - 1]), i - r + 1);
            res = max(res, (l == -1 ? 0 : dp[l]) + i - r + 1);
        }
        cout << res << endl;
    }
}