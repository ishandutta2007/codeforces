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

const int N = 300 + 2, mod = 1e9 + 7;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(6);
    int tt; cin >> tt;
    while (tt --> 0) {
        int n; cin >> n;
        if (n <= 26) {
            for (int i = 0; i < n; ++i) cout << (char)('a' + i);
            cout << '\n';
        }
        else {
            if (n & 1) cout << "pchel", n -= 5;
            for (int i = 0; i < n / 2; ++i) cout << "a";
            cout << "b";
            for (int i = 0; i < n / 2 - 1; ++i) cout << "a";
            cout << '\n';
        }
    }
    cout << '\n';
    return 0;
}