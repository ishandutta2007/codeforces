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

    int n, a, d;
    cin >> n >> a >> d;
    double last = 0;
    for(int i = 0;i < n;i++) {
        int t, v;
        cin >> t >> v;
        double temp = (double) v * v / (2 * a);

        double res = 0;

        if (temp <= d) {
            res = (double)v / a + (d - temp) / v;
        }else {
            res = sqrt((double)2 * d / a);
        }

        last = max(last, res + t);
        cout << last << endl;
    }
}