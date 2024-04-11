#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <string>
#include <stack>
#include <cmath>
#include <set>
#include <map>
#include <deque>
#include <iterator>
#include <sstream>
#define endl "\n"
#define int long long
#define ld long double
#define debug(x) cout << #x << " is " << x << endl;
using namespace std;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(6);
    int tt; cin >> tt;
    while(tt--) {
        int n; cin >> n;
        vector <int> a(n), b(n);
        int ma = 1e9, mb = 1e9;
        for (auto& x : a) {
            cin >> x;
            ma = min(ma, x);
        }
        for (auto& x : b) {
            cin >> x;
            mb = min(mb, x);
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += max(a[i] - ma, b[i] - mb);
        }
        cout << ans << "\n";
    }
    return 0;
}