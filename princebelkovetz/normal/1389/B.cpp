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
    while (tt-- > 0) {
        int n, k, z; cin >> n >> k >> z;
        vector <int> a(n), pref(n + 1);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            pref[i + 1] = pref[i] + a[i];
        }
        int ans = pref[k + 1];
        for (int i = 1; i < n; ++i) {
            int cur = pref[i + 1], curz = z, curm = k - i;
            int f = 1;
            if (curm < 0 or curz <= 0) break;
            while (1) {
                if (f and curz > 0 and curm > 0) {
                    f = 1 - f;
                    cur += a[i - 1];
                    curm--; curz--;
                }
                else if (!f and curm > 0) {
                    f = 1 - f;
                    cur += a[i];
                    curm--;
                }
                else break;
            }
            cur += pref[i + curm + f] - pref[i + f];
            ans = max(ans, cur);
        }
        cout << ans << "\n";

    }
    return 0;
}