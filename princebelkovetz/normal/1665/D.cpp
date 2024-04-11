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
#include <chrono>
#include <unordered_set>

#define int long long
#define ld long double
#define debug(x) cout << #x << " is " << x << '\n';

using namespace std;
const int root = 212, mod = 1e18 + 7, N = 5e5 + 2;

int guess(int a, int b) {
    cout << "? " << a << ' ' << b << endl;
    int res; cin >> res;
    return res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(6);

    int tt; cin >> tt;
    while (tt--) {
        int ans = 0;
        for (int i = 0; i < 30; ++i) {
            if (guess((3ll << i) - ans, (1ll << i) - ans) >= (2ll << i))
                ans += 1ll << i;
        }
        cout << "! " << ans << endl;
    }

    return 0;
}