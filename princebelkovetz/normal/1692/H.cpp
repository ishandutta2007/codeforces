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
        int n; cin >> n;
        vector <int> a(n);
        for (auto& x : a) cin >> x;

        map <int, vector <pair <int, int>>> ids;
        for (int i = 0; i < n; i++) {
            int curId = (ids.find(a[i]) == ids.end() ? 0 : ids[a[i]].size());
            ids[a[i]].push_back({ 2 * curId - i, i });
        }

        int ans = -mod * mod, idL = -1, idR = -1, val = -1;

        for (auto& x : ids) {
            int bestId = -1, curMin = mod * mod;
            for (auto& y : x.second) {
                if (y.first < curMin) {
                    curMin = y.first;
                    bestId = y.second;
                }
                if (y.first - curMin > ans) {
                    ans = y.first - curMin;
                    idL = bestId + 1;
                    idR = y.second + 1;
                    val = x.first;
                }
            }
        }

        cout << val << ' ' << idL << ' ' << idR << '\n';
    }

    return 0;
}