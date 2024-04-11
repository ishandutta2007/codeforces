#include <iostream>
#include <random>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <algorithm>
#include <bitset>
#include <iomanip>
#include <queue>
#include <cmath>
#include <chrono>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;
const ll INF = 1e18;
const int INFi = 1e9 * 2;
const int maxN = 1e6 + 1;
ll md = 1000000007;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

vector<pair<int, int>> g[maxN];

void solve() {
    ll u, v; cin >> u >> v;
    if (u > v || (u&1) != (v&1)) {
        cout << -1;
        return;
    }
    if (u == v && u == 0) {
        cout << 0;
        return;
    }
    if (u == v) {
        cout << 1 << "\n";
        cout << u;
        return;
    }
    ll a1 = 0, b1 = 0;
    for(ll i = 0; i < 62; ++i) {
        ll x = 1ll << i;
        if (x > 1e18) break;
        if ((u & x) && (v & x)) {
            a1 += x;
        } else if ((u & x) != (v & x)) {
            if (i != 0 && !((a1 + b1) & x)) {
                ll y = 1ll << (i-1);
                a1 += y;
                b1 += y;
            }
            if ((u & x)) {
                a1 += x;
            }
        }
    }
    if (((a1 ^ b1) == u) && (a1 + b1 == v)) {
        cout << 2 << "\n";
        cout << a1 << " " << b1;
    } else {
        cout << 3 << "\n";
        ll w = v - u;
        w /= 2;
        cout << u << " " << w << " " << w;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests = 1;
    range(_, tests) {
        solve();
    }
    return 0;
}