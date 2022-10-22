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

#define ld long double
#define debug(x) cout << #x << " is " << x << '\n';
#define int long long

using namespace std;
const int root = 212, mod = 1e9 + 7, N = 1e6 + 7;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(6);

    int n; cin >> n;
    vector <int> a(n);
    int mn = mod, mx = -mod;
    for (auto& x : a) {
        cin >> x;
        mn = min(mn, x), mx = max(mx, x);
    }

    if (mx - mn < 2) {
        cout << n << '\n';
        for (auto& x : a) cout << x << ' ';
        cout << '\n';
    }
    else {
        int mxC = 0, mnC = 0, mdC = 0;
        for (auto& x : a)
            mxC += (x == mx), mnC += (x == mn);
        mdC = n - mxC - mnC;
        if (mdC - mdC % 2 > 2 * min(mxC, mnC)) {
            cout << n - mdC + mdC % 2 << '\n';
            for (int i = 0; i < mxC + mdC / 2; ++i)
                cout << mx << ' ';
            for (int i = 0; i < mnC + mdC / 2; ++i)
                cout << mn << ' ';
            if (mdC & 1) cout << mx - 1 << ' ';
        }
        else {
            cout << n - 2 * min(mxC, mnC) << '\n';
            for (int i = 0; i < mxC - min(mxC, mnC); ++i)
                cout << mx << ' ';
            for (int i = 0; i < mnC - min(mxC, mnC); ++i)
                cout << mn << ' ';
            for (int i = 0; i < mdC + 2 * min(mxC, mnC); ++i)
                cout << mx - 1 << ' ';
        }
        cout << '\n';
    }


    return 0;
}