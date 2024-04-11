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
        int a, b, x, y, n;
        cin >> a >> b >> x >> y >> n;
        int res1, res2;
        res1 = (a - min(a - x, n)) * (b - min(b - y, n - min(a - x, n)));
        res2 = (a - min(a - x, n - min(b - y, n))) * (b - min(b - y, n));

        cout << min(res1, res2) << endl;
    }
}