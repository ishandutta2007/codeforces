#include <bits/stdc++.h>
using namespace std;
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
 
#define int long long
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair<int, int>
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
 
    int k, d, t;
    cin >> k >> d >> t;
    t *= 2;
    int s = ((k - 1) / d + 1) * d - k;
 
    int l = -1;
    int r = 2e18;
    bool lower = false; 
    while(r - l > 1) {
        int mid = (l + r) / 2;
        int res = mid / (k + s) * (2 * k + s);
 
        int num = mid % (k + s);
        res += min(num, k) * 2;
        res += max(0ll, num - k);
 
        if (res >= t) {
            //if (mid == 7) cout << res << " " << num << endl;
            if (res == t + 1 && num <= k) lower = true;
            r = mid;
        }
        else l = mid;
    }
 
    if (lower) cout << (double)r - 0.5 << endl;
 
    else cout << r << endl;
}