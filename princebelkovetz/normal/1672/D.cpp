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
const int root = 212, mod = 1e9 + 7, N = 5e5 + 2, L = 30;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(6);
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector <int> a(n), b(n);
        for (auto& x : a) cin >> x;
        for (auto& x : b) cin >> x;
        bool ok = true;
        map <int, int> cnt;
        int id = n - 1;
        for (int i = n - 1; i >= 0; --i) {
            if (id == -1 or b[id] != a[i]) {
                if (cnt[a[i]] > 0) {
                    cnt[a[i]]--;
                    continue;
                }
                else {
                    ok = false;
                    break;
                }
            }
            int j = id;
            while (j >= 0 and b[j] == b[id]) --j;
            int need = id - j;
            cnt[a[i]] += need - 1;
            id = j;
        }
        cout << (ok ? "YES" : "NO") << '\n';
    }
    return 0;
}