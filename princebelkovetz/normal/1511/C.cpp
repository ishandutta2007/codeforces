#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <iomanip>
#include <cassert>
#include <functional>
using namespace std;
#define ld long double
#define int long long
#define debug(x) cout << #x << " actually equals " << x << '\n';
constexpr int mod = 998244353;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout << fixed << setprecision(6);
    int n, q; cin >> n >> q;
    map <int, int> mn;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        if (mn.find(x) == mn.end())
            mn[x] = i + 1;
    }
    while (q-- > 0) {
        int c; cin >> c;
        cout << mn[c] << ' ';
        for (auto& x : mn)
            if (x.second < mn[c])
                x.second++;
        mn[c] = 1;
    }
    cout << '\n';
    return 0;
}