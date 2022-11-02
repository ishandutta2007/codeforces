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
 
    int p, y;

    cin >> p >> y;
    int res = y;
    bool good = false;

    while(res > p) {
        bool bad = false;
        for(int i = 2;i * i <= res && i <= p;i++) {
            if (res % i == 0) bad = true;
            if (bad) break;
        }
        if (bad) res--;
        else {
            good = true;
            cout << res;
            break;
        }
    }
    if (!good) cout << -1;

}