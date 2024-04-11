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
        map <int, int> a;
        for (int i = 0; i < n; ++i) {
            int x; cin >> x;
            a[x]++;
        }
        int ans = 0;
        for (int i = 2; i <= 2 * n; ++i) {
            int cur = 0;
            for (auto x : a) {
                if (x.first > n) break;
                if (a.find(i - x.first) == a.end()) continue;
                else {
                    cur += min(x.second, a[i - x.first]);
                }
            }
            ans = max(ans, cur / 2);
        }
        cout << ans << "\n";
    }
    return 0;
}