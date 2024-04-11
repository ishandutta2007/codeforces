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
#include <random>

using namespace std;

#define debug(x) cout << #x << " is " << x << '\n';
#define ld long double
#define int long long

const int mod = 998244353, N = 5e3 + 7;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(12);

    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        set <int> ans;
        for (int i = 0, x; i < n; ++i) {
            cin >> x;
            ans.insert(x * (1 - 2 * (ans.find(x) != ans.end())));
        }
        cout << ans.size() << '\n';
    }

    return 0;
}