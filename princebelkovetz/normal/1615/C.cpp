#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <iomanip>
#include <queue>
#include <cassert>
#include <bitset>
#include <string>
#include <numeric>
#include <climits>

using namespace std;

#define debug(x) cout << #x << " is " << x << '\n';
#define ld long double
#define int long long

const int mod = 1e9 + 7, N = 2e5 + 7;

vector <vector <int>> cnt(2, vector <int>(2));

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(12);
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        string s, t; cin >> s >> t;
        cnt[0][0] = cnt[0][1] = cnt[1][0] = cnt[1][1] = 0;
        for (auto& x : s)
            cnt[0][x - '0']++;
        for (auto& x : t)
            cnt[1][x - '0']++;
        int ans = mod, diff = 0;
        for (int i = 0; i < n; ++i)
            diff += s[i] != t[i];
        if (cnt[0] == cnt[1]) {
            ans = diff;
        }
        if (cnt[0][1] > 0 and cnt[0][0] + 1 == cnt[1][1] and cnt[0][1] - 1 == cnt[1][0]) {
            for (int i = 0; i < n; ++i) {
                if (s[i] == '0') continue;
                ans = min(ans, n - (diff - (s[i] != t[i])));
            }
        }
        cout << (ans == mod ? -1 : ans) << '\n';
    }
    
}