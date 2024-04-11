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
#include <bitset>

#pragma GCC optimize("O3")
#define ld long double
#define debug(x) cout << #x << " is " << x << '\n';
#define int long long

using namespace std;
const int root = 212, mod = 1e9 + 7, K = 21;

int bits(int x) {
    int res = 0;
    for (int i = 0; i < 41; ++i)
        res += (x >> i) & 1;
    return res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(6);

    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        int ans = bits(n);
        vector <int> fct = { 6 };
        while (fct.back() <= n) {
            fct.push_back(fct.back() * (fct.size() + 3));
        }
        fct.pop_back();
        for (int i = 0; i < (1ll << fct.size()); ++i) {
            int cur = 0, cnt = 0;
            for (int j = 0; j < fct.size(); ++j)
                if ((i >> j) & 1) cnt++, cur += fct[j];
            if (cur <= n) ans = min(ans, cnt + bits(n - cur));
        }
        cout << ans << '\n';
    }

    return 0;
}