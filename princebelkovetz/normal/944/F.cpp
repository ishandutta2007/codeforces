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

#define ld long double
#define debug(x) cout << #x << " is " << x << '\n';
#define int long long

using namespace std;
const int root = 212, mod = 1e9 + 7, N = 20;

int solve(vector <vector <int>> p) {
    if (p.empty()) return 0;
    sort(p.begin(), p.end());
    int cur = 0, mn = mod, mx = -mod;
    for (auto& x : p) {
        mn = min({ mn, x[0], x[1] });
        mx = max({ mx, x[0], x[1] });
    }
    for (auto& x : p)
        x[0] -= mn, x[1] -= mn;
    mx -= mn - 1;

    // prefix
    int prefId = 0;
    vector <int> prefUp(mx + 2, -mod), prefDn(mx + 2, mod);
    for (int i = 0; i < mx; ++i) {
        if (i & 1) {
            prefUp[i + 2] = prefUp[i];
            prefDn[i + 2] = prefDn[i];
        }
        else {
            while (prefId < p.size() and p[prefId][0] == i) {
                prefUp[i + 1] = max(prefUp[i + 1], p[prefId][1]);
                prefDn[i + 1] = min(prefDn[i + 1], p[prefId][1]);
                prefId++;
            }
        }
    }
    // suffix
    int sufId = p.size() - 1;
    vector <int> sufUp(mx + 2, -mod), sufDn(mx + 2, mod);
    for (int i = mx - 1; i >= 1; --i) {
        if (i & 1) {
            sufUp[i] = max(sufUp[i], sufUp[i + 2]);
            sufDn[i] = min(sufDn[i], sufDn[i + 2]);
        }
        else {
            while (sufId >= 0 and p[sufId][0] == i) {
                sufUp[i - 1] = max(sufUp[i - 1], p[sufId][1]);
                sufDn[i - 1] = min(sufDn[i - 1], p[sufId][1]);
                sufId--;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i < mx; i += 2) {
        ans += max(0ll, (min(sufUp[i], prefUp[i]) - max(sufDn[i], prefDn[i])) / 2);
    }
    return ans;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(8);

    int n; cin >> n;
    vector <vector <vector <int>>> ps(2);
    vector <int> mn(2);
    for (int i = 0, x, y; i < n; ++i) {
        cin >> x >> y;
        ps[(x + y) & 1].push_back({ x + y, x - y });
    }
    cout << solve(ps[0]) + solve(ps[1]) << '\n';

    return 0;
}