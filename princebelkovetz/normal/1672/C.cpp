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
        vector <int> a(n);
        for (auto& x : a) cin >> x;
        int f = -1, s = -1;
        for (int i = 0; i < n - 1; ++i) {
            if (a[i] == a[i + 1]) {
                s = i;
                if (f == -1) f = i + 1;
            }
        }
        if (f != -1 and s == f) cout << "1\n";
        else cout << max(0ll, s - f) << '\n';
    }
    return 0;
}