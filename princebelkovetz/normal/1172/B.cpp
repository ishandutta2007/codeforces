#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <set>
#include <stack>
#include <map>
#include <queue>
#include <cassert>
#include <numeric>
#include <climits>

#define int long long
#define ld long double
#define debug(x) cout << #x << " is " << x << '\n';

using namespace std;
const int root = 212, mod = 998244353, N = 5e5 + 2, L = 30;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(6);

    int n; cin >> n;
    vector <int> deg(n + 1), fct(n + 1);
    fct[0] = 1;
    for (int i = 1; i <= n; ++i) {
        fct[i] = fct[i - 1] * i % mod;
    }
    for (int i = 0, u, v; i < n - 1; ++i) {
        cin >> u >> v;
        deg[u]++, deg[v]++;
    }

    int ans = n;
    for (int i = 1; i <= n; ++i) {
        ans = ans * fct[deg[i]] % mod;
    }
    cout << ans << '\n';

    return 0;
}