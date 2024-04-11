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
#pragma GCC optimize("O3")

using namespace std;

#define debug(x) cout << #x << " is " << x << '\n';
#define ld long double
#define int long long

const int mod = 1e9 + 7, N = 4e2 + 2;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(12);
    int tt; cin >> tt;
    while (tt--) {
        int cur = 1;
        bool died = false;
        int n, s0 = 0, s1 = 0; cin >> n;
        for (int i = 0, x; i < n; ++i) {
            cin >> x;
            if (!x) {
                s0++, s1 = 0;
                if (s0 == 2) died = true;
            }
            else {
                s1++, s0 = 0;
                if (s1 > 1) cur += 5;
                else cur++;
            }
        }
        cout << (died ? -1 : cur) << '\n';
    }
}