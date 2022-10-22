#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cassert>
using namespace std;
#define int long long
#define ld long double
#define debug(x) cout << #x << " is " << x << '\n';

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(6);
    
    int n; cin >> n;
    int l = 1, r = n + 2;
    vector <int> a(n);
    while (l + 1 < r) {
        int m = (l + r) / 2;
        int x, y;
        if (m == n + 1) x = 1e6;
        else if (a[m - 1] == 0) {
            cout << "? " << m << endl;
            cin >> x;
        }
        else x = a[m - 1];
        if (m - 1 == 0) y = 0;
        else if (a[m - 2] == 0) {
            cout << "? " << m - 1 << endl;
            cin >> y;
        }
        else y = a[m - 2];
        if (m - 1 < n) a[m - 1] = x;
        if (m - 2 > 0) a[m - 2] = y;
        if (y < x) r = m;
        else l = m;
    }
    cout << "! " << l << endl;
    return 0;
}