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
#include <functional>

#define ll long long
#define ld long double
#define debug(x) cout << #x << " is " << x << '\n';

using namespace std;
const int mod = 1e9 + 7, N = 2e2 + 5, K = 2e3 + 20;

inline void add(int& a, int b) {
    a += b;
    if (a >= mod) a -= mod;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(8);
    
    int n, k; cin >> n >> k;
    vector <int> a(n);
    for (auto& x : a) cin >> x;
    sort(a.begin(), a.end());
    vector <vector <int>> curDp(K, vector <int>(N));
    vector <vector <int>> newDp(K, vector <int>(N));
    curDp[0][0] = 1;
    for (int i = 0; i < n; ++i) {
        newDp.assign(K, vector <int>(N, 0));
        for (int j = 0; j < K; ++j) {
            for (int g = 0; g <= n; ++g) {
                int diff = a[i];
                if (i) diff -= a[i - 1];
                diff *= g;
                if (j + diff >= K) break;
                add(newDp[j + diff][g + 1], curDp[j][g]);
                add(newDp[j + diff][g], (ll)(g + 1) * curDp[j][g] % mod);
                if (g)
                    add(newDp[j + diff][g - 1], (ll)curDp[j][g] * g % mod);
            }
        }
        curDp.swap(newDp);
    }
    int ans = 0;
    for (int i = 0; i <= k; ++i)
        add(ans, curDp[i][0]);
    cout << ans << '\n';

    return 0;
}