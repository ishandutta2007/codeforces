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

#define int long long
#define ld long double
#define debug(x) cout << #x << " is " << x << '\n';

using namespace std;
const int root = 212, mod = 1e9 + 7, L = 62, N = 503, LIMIT = 1e18;

bitset <N> g[L][2][N];

void make_unique(vector <int>& a) {
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(8);
    
    int n, m; cin >> n >> m;
    // type, len, i
   
    for (int i = 0, u, v, t; i < m; ++i) {
        cin >> u >> v >> t;
        g[0][t][u][v] = 1;
    }
    for (int len = 1; len < L; ++len) {
        for (int t = 0; t < 2; ++t) {
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= n; ++j) {
                    if (g[len - 1][t][i][j])
                        g[len][t][i] |= g[len - 1][t ^ 1][j];
                }
            }
        }
    }
    int t = 0, ans = 0;
    bitset <N> cur;
    cur[1] = 1;
    for (int len = L - 1; len >= 0; --len) {
        bitset <N> able;
        for (int i = 1; i <= n; ++i) {
            if (cur[i]) able |= g[len][t][i];
        }
        if (!able.count()) continue;
        ans += 1ll << len;
        cur = able;
        t ^= 1;
    }
    
    cout << (ans >= LIMIT ? -1 : ans) << '\n';
    
    return 0;
}