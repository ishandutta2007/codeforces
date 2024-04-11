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
        int n, m; cin >> n >> m;
        string s; cin >> s;
        vector <int> pref(n * m + 1);
        for (int i = 0; i < n * m; ++i) {
            pref[i + 1] = pref[i] + (s[i] == '1');
        }
        vector <int> ans(n * m);
        for (int i = 0; i < m; ++i) {
            int cur = 0;
            int rx = i + 1, lx = rx - m;
            for (int j = 0; j < n; ++j) {
                if (j == 0) cur = pref[i + 1] > 0;
                else cur += (pref[rx] - pref[lx]) > 0;
                ans[j * m + i] = cur;
                rx += m, lx += m;
            }
        }
        int cur = 0;
        vector <int> cnt(m);
        for (int i = 0; i < n * m; i++) {
            cur -= (cnt[i % m] > 0);
            cnt[i % m] += (s[i] == '1');
            cur += (cnt[i % m] > 0);
            ans[i] += cur;
        }
        for (auto& x : ans) cout << x << ' ';
        cout << '\n';
    }
    return 0;
}