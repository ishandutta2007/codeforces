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
#define sz(a) ((int) a.size())
#define all(_v) _v.begin(), _v.end()
#define what_is(x) cout << #x << " is " << x << endl;
typedef double ld;
const int inf = 1e15;


signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> dp(n + 5), a(n + 1);
        for(int i = 0;i <= n;i++) {
            if (i != n) cin >> a[i];

            int v1 = i >= 2 ? dp[i - 2] : inf;
            int v2 = i >= 3 ? dp[i - 3] : inf;
            int v3 = i >= 4 ? dp[i - 4] : inf;

            dp[i] = min(a[i] + min(v1, v2), a[i] + a[i - 1] + min(v2, v3));

            if (i == 0) dp[i] = a[i];
            else if (i == 1) dp[i] = a[i] + a[i - 1];
        }

            /*for(int i = 0;i < n;i++)
                cout << dp[i] << " ";*/
        cout << dp[n] << endl;
    }
}