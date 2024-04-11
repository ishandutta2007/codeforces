#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <set>
#include <stack>
#include <map>
#include <queue>
#include <cassert>
#include <numeric>
#include <climits>

#define int long long
#define ld long double
#define debug(x) cout << #x << " is " << x << '\n';

using namespace std;
const int root = 212, mod = 1e9 + 7, B = 60, N = 1e3 + 15;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(6);

    int tt; cin >> tt;
    while (tt--) {
        int n, S; cin >> n >> S;
        vector <int> a(n);
        for (auto& x : a) cin >> x;
        int curR = 0, curS = 0;
        int ans = mod;
        for (int i = 0; i < n; i++) {
            while (curS <= S and curR < n) {
                if (curS + a[curR] > S) break;
                curS += a[curR++];
            }
            if (curS < S) break;
            ans = min(ans, n - curR + i);
            curS -= a[i];
        }
        cout << (ans == mod ? -1 : ans) << '\n';
    }

    return 0;
}