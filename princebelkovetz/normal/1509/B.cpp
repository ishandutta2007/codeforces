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
    cout << fixed << setprecision(1);
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        string s; cin >> s;
        int cntT = 0, cntM = 0, bal = 0, mn = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'T') {
                cntT++, bal++;
            }
            else {
                cntM++, bal--;
            }
            if (cntT - n / 3 > cntM) mn = -100;
            mn = min(mn, bal);
        }
        if (cntT == cntM * 2 and mn >= 0)
            cout << "YES\n";
        else 
            cout << "NO\n";
    }
    return 0;
}