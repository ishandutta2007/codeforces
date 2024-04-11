#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
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
        int n; cin >> n;
        if (n == 1) cout << 0;
        else if (n == 2) cout << 1;
        else if (n == 3) cout << 2;
        else if (n & 1) cout << 3;
        else cout << 2;
        cout << '\n';
    }
    return 0;
}