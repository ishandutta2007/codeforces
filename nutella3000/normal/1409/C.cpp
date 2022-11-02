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
        int n, x, y;
        cin >> n >> x >> y;
        for(int d = 1;d <= 50;d++) {
            if ((y - x) % d == 0 && (y - x) / d < n) {
                vector<int> a(n);
                for(int i = n - 1;i >= 0;i--) 
                    a[i] = max(y, (n - 1) * d + y % d + (y % d ? 0 : d)) - (n - 1 - i) * d;

                for(int i = 0;i < n;i++)
                    cout << a[i] << " ";
                cout << endl;
                break;
            }
        }
    }
}