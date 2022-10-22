#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#include <cassert>
#define int long long
#define ld long double
#define debug(x) cout << #x << " is " << x << endl;
using namespace std;
const int mod = 1e9 + 7;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(7);
    int tt; cin >> tt;
    while (tt--) {
        int d, k; cin >> d >> k;
        int x = 0;
        int a = 0;
        while (a * a + a * a <= d * d)
            a += k;
        a -= k;
        if ((a + k) * (a + k) + a * a <= d * d)
            a += k, x = 1 - x;
        cout << (x ? "Ashish" : "Utkarsh") << '\n';
    }
    return 0;
}