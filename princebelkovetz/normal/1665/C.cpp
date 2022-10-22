#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <stack>
#include <map>
#include <unordered_map>
#include <queue>
#include <iterator>
#include <sstream>
#include <cassert>
#include <locale>
#include <numeric>
#include <random>
#include <chrono>
#include <unordered_set>

#define int long long
#define ld long double
#define debug(x) cout << #x << " is " << x << '\n';

using namespace std;
const int root = 212, mod = 1e18 + 7, N = 5e5 + 2;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(6);

    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector <int> cnt(n + 1);
        for (int p, i = 2; i <= n; ++i) {
            cin >> p;
            cnt[p]++;
        }
        cnt[0]++;
        vector <int> ids(n + 1);
        iota(ids.begin(), ids.end(), 0);
        sort(ids.begin(), ids.end(), [&](int i, int j) {return cnt[i] < cnt[j]; });
        int curCnt = 0, ans = 0;
        vector <int> vals;
        for (auto& x : ids) {
            if (cnt[x] == 0) continue;
            cnt[x] -= curCnt + 1;
            if (cnt[x] > 0) {
                vals.push_back(cnt[x]);
            }
            curCnt++, ans++;
        }
        int l = -1, r = n;
        while (l + 1 < r) {
            int m = (l + r) / 2;
            int need = 0;
            for (auto& x : vals) {
                need += max(0ll, x - m);
            }
            if (need > m) l = m;
            else r = m;
        }
        cout << ans + r << '\n';
    }

    return 0;
}