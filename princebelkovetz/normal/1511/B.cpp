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
    int tt; cin >> tt;
    while (tt--) {
        int a, b, c; cin >> a >> b >> c;
        a -= c - 1, b -= c - 1;
        for (int i = 0; i < a; ++i)
            cout << 3;
        for (int i = 0; i < c - 1; ++i)
            cout << 0;
        cout << " 1";
        for (int i = 0; i < b - 1; ++i)
            cout << 0;
        for (int i = 0; i < c - 1; ++i)
            cout << 0;
        cout << '\n';
    }
    return 0;
}