#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <set>
#include <stack>
#include <map>
#include <cassert>
#include <numeric>

#define int long long
#define ld long double
#define debug(x) cout << #x << " is " << x << '\n';

using namespace std;
const int root = 212, mod = 1e18 + 7, N = 5e5 + 2, L = 20;

vector <vector <int>> binup;
vector <int> dep;

int getDist(int u, int v) {
    if (u == v) return 0;
    if (dep[u] < dep[v]) swap(u, v);
    
    int ans = dep[u] + dep[v];
    for (int i = L - 1; i >= 0; --i) {
        if (dep[u] - (1ll << i) >= dep[v])
            u = binup[i][u];
    }

    for (int i = L - 1; i >= 0; --i) {
        if (binup[i][u] != binup[i][v])
            u = binup[i][u], v = binup[i][v];
    }
    u = binup[0][u];
    return ans - 2 * dep[u];
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(6);

    int q; cin >> q;
    binup.resize(L, vector <int>(2 * q + 10));
    dep.resize(2 * q + 10);
    dep[2] = dep[3] = dep[4] = 1;

    int far = 2, n = 4, diam = 2;
    for (int i = 1; i <= 4; ++i)
        for (int j = 0; j < L; ++j) binup[j][i] = 1;

    while (q--) {
        int x; cin >> x;
        binup[0][n + 1] = binup[0][n + 2] = x;
        dep[n + 1] = dep[n + 2] = dep[x] + 1;
        for (int i = 1; i < L; ++i) 
            binup[i][n + 1] = binup[i][n + 2] = binup[i - 1][binup[i - 1][n + 1]];
        if (dep[x] == dep[far]) {
            far = n + 1;
            diam++;
        }
        else {
            diam = max(diam, getDist(n + 1, far));
        }
        n += 2;
        cout << diam << '\n';
    }


    return 0;
}