#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cstring>
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

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(6);
    int tt; cin >> tt;
    while (tt-- > 0) {
        int n, m, ans = 0;
        cin >> n >> m;
        vector <pair <int, int>> a(m);
        for (auto& x : a) 
            cin >> x.first >> x.second;
        sort(a.rbegin(), a.rend());
        vector <int> pref(m + 1);
        for (int i = 0; i < m; ++i) 
            pref[i + 1] = pref[i] + a[i].first;
        for (int i = 0; i < m; ++i) {
            int l = -1, r = m;
            while (l + 1 < r) {
                int m = (l + r) / 2;
                if (a[m].first >= a[i].second) l = m;
                else r = m;
            }
            int cur = 0;
            if (l == -1) cur = a[i].first + a[i].second * (n - 1);
            else {
                l = min(l, n - 1);
                cur = pref[l + 1];
                int curn = n - l - 1;
                if (curn > 0) {
                    if (l < i) {
                        cur += a[i].first;
                        --curn;
                    }
                    cur += a[i].second * (curn);
                }
            }
            ans = max(ans, cur);
        }
        cout << ans << endl;
    }
    return 0;
}