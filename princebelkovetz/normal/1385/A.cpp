#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <iterator>
#include <sstream>
#define endl "\n"
#define int long long
#define ld long double
#define debug(x) cout << #x << " is " << x << endl;
using namespace std;
const ld eps = 1e-8;
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(7);
    int t; cin >> t;
    while (t-- > 0) {
        vector <int> a(3);
        for (auto& x : a) cin >> x;
        sort(a.begin(), a.end());
        if (a[1] != a[2]) cout << "NO\n";
        else {
            cout << "YES\n";
            cout << a[2] << " " << a[0] << " " << a[0] << endl;
        }
    }
}