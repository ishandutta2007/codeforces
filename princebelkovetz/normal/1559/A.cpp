#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <iomanip>
#include <queue>
#include <cassert>
#include <bitset>

using namespace std;

#define debug(x) cout << #x << " is " << x << '\n';
#define ld long double
#define int long long

const int mod = 1e9 + 7;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(6);
    
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector <int> a(n);
        for (auto& x : a) cin >> x;
        int ans = a[0];
        for (auto& x : a) ans &= x;
        cout << ans << '\n';
    }

    return 0;
}