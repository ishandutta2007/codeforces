#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <set>
#include <stack>
#include <map>
#include <cassert>
#include <numeric>

#define int long long
#define ld long double
#define debug(x) cout << #x << " is " << x << '\n';

using namespace std;
const int root = 212, mod = 1e18 + 7, N = 5e5 + 2, L = 30;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(6);

    int tt; cin >> tt;
    while (tt--) {
        int n, cntOnes = 0, curD = 0; cin >> n;
        vector <int> a(n), ans(n), d(n);
        for (auto& x : a) cin >> x, cntOnes += x;
        cntOnes /= n;
        for (int i = n - 1; i >= 0; --i) {
            a[i] -= curD;
            curD += d[i];
            ans[i] = (a[i] == i + 1);
            if (i - cntOnes + 1 < i) d[i - cntOnes + 1]--, curD++;
            if (ans[i] == 1) cntOnes--;
        }
        for (auto& x : ans) cout << x << ' ';
        cout << '\n';
    }


    return 0;
}