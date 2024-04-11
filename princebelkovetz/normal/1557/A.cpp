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
#include <random>

using namespace std;
mt19937 rnd(239);

#define debug(x) cout << #x << " is " << x << '\n';
#define ld long double

const int mod = 1e9 + 7, p = 239, N = 2e5 + 5;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(6);

    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector <int> a(n);
        for (auto& x : a) cin >> x;
        sort(a.begin(), a.end());
        ld ans = 0;
        for (auto& x : a) ans += x;
        cout << (ans - a.back()) / (n - 1) + a.back() << '\n';
    }

    return 0;
}