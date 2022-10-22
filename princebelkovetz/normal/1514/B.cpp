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
#define int long long
#define ld long double
#define debug(x) cout << #x << " actually equals " << x << '\n';
constexpr int mod = 1e9 + 7;
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int testcases;
    cin >> testcases;
    while (testcases --> 0) {
        int n, k; cin >> n >> k;
        int res = 1;
        for (int i = 0; i < k; ++i)
            res = (res * n) % mod;
        cout << res << '\n';
    }
    return 0;
}