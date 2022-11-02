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
 
    int n;
    cin >> n;
    int res = 0;
    int h = 0;
    for(int i = 1e6;i >= 0;i--) {
        h = max(0ll, h - 2);
        while(true) {
            double y = (double)i / 2 * 3;
            double x = sqrt(3) * h;
 
            if (i % 2 != 0) {
                x += sqrt(3) / 2;
            }
 
            double dist1 = hypot(x, y + 1);
            double dist2 = hypot(x + sqrt(3) / 2, y + 0.5);
 
            //cout << i << " " << dist1 << " " << dist2 << " " << h << endl;
 
            if (max(dist1, dist2) - n <= 1e-9) h++;
            else break;
        }
 
        res += 2 * h;
        if (i % 2 == 0 && h != 0) res--;
 
        if (i == 1) res *= 2;
    }
 
    cout << res;
}