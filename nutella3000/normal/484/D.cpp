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
#define sz(a) ((int)a.size())
#define what_is(x) cout << #x << " is " << x << endl;
typedef long double ld;
 
const ll inf = 1e17 + 7;


signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);

    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> dp(n);
    for(int i = 0;i < n;i++) {
        cin >> a[i];
    }

    int id = 0;
    bool up = true;

    for(int i = 1;i < n;i++) {
        if (up ^ (a[i] > a[i - 1])) {
            id = i - 1;
            up = !up;
        }

        dp[i] = dp[i - 1];
        int num = (id == 0 ? 0 : dp[id - 1]);
        dp[i] = max(dp[i], num + abs(a[i] - a[id]));
        dp[i] = max(dp[i], dp[id] + abs(a[i] - a[id + 1]));
    }

    cout << dp[n - 1];
}