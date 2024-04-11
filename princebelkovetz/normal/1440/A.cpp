#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <unordered_map>
#include <queue>
#include <cassert>
#define int long long
#define ld long double
#define debug(x) cout << #x << " is " << x << endl;
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(7);
    int tt; cin >> tt;
    while (tt --> 0) {
        int n, c0, c1, h;
        cin >> n >> c0 >> c1 >> h;
        string s; cin >> s;
        int cnt0 = 0, cnt1 = 0;
        for (auto x : s)
            cnt0 += x == '0', cnt1 += x == '1';
        int ans = cnt0 * c0 + cnt1 * c1;
        for (int i = 0; i <= cnt0; ++i) {
            ans = min(ans, (cnt0 - i) * c0 + (cnt1 + i) * c1 + h * i);
        }
        for (int i = 0; i <= cnt1; ++i) {
            ans = min(ans, (cnt0 + i) * c0 + (cnt1 - i) * c1 + h * i);
        }
        cout << ans << '\n';
    }
	return 0;
}