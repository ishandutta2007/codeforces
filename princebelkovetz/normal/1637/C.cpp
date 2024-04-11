#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <stack>
#include <map>
#include <queue>
#include <iterator>
#include <sstream>
#include <cassert>
#include <locale>
#include <numeric>

#define ld long double
#define debug(x) cout << #x << " is " << x << '\n';
#define int long long

using namespace std;
const int mod = 998244353, N = 2e5 + 3;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(6);

    int tt;
    cin >> tt;
    while (tt --> 0) {
        int n; cin >> n;
        vector <int> a(n);
        for (auto& x : a) cin >> x;
        if (n == 3 and a[1] & 1) {
            cout << "-1\n";
            continue;
        }
        int ans = 0, ok = 0;
        for (int i = 1; i < n - 1; ++i) {
            if (a[i] > 1) ok = 1;
            ans += (a[i] + 1) / 2;
        }
        cout << (ok ? ans : -1) << '\n';
    }

    return 0;
}