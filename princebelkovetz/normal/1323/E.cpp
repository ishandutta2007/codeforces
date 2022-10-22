#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cmath>
#include <string>
#include <stack>
#include <map>
#include <queue>
#include <iterator>
#include <sstream>
#include <cassert>
#include <locale>
#include <numeric>
#include <random>
#include <functional>
#include <set>

#define ld long double
#define debug(x) cout << #x << " is " << x << '\n';
#define int long long

using namespace std;
const int N = 2e5, mod = 1e13 + 7, p = 464;


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(6);

    int tt; cin >> tt;
    while (tt--) {
        int n, m; cin >> n >> m;
        vector <int> a(n);
        for (auto& x : a) cin >> x;
        vector <vector <int>> g(n);
        for (int i = 0, u, v; i < m; ++i) {
            cin >> u >> v;
            g[v - 1].push_back(u);
        }
        map <vector <int>, int> cnt;
        int id = 0;
        for (auto& x : g) {
            id++;
            if (x.empty()) continue;
            sort(x.begin(), x.end());
            cnt[x] += a[id - 1];
        }
        int ans = 0;
        auto gcd = [&](int i, int j, auto gcd) {
            if (!j) return i;
            return gcd(j, i % j, gcd);
        };
        for (auto& x : cnt)
            ans = gcd(ans, x.second, gcd);
        cout << ans << '\n';
    }

    return 0;
}