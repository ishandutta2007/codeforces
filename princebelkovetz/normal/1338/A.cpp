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
    while (t--) {
        int n; cin >> n;
        vector <int> a(n);
        for (auto& x : a) cin >> x;
        int ans = 0;
        for (int i = 1; i < n; ++i) {
            int cur = 1, ok = 0;
            while (a[i] < a[i - 1]) {
                a[i] += cur;
                cur *= 2; ++ok;
            }
            ans = max(ans, ok);
            for (int j = ok; j >= 0; --j) {
                cur /= 2;
                if (a[i] - cur >= a[i - 1]) a[i] -= cur;
            }
        }
        cout << ans << endl;
    }
}