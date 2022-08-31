#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <map>
#include <unordered_set>
#include <tuple>
#include <queue>
#include <set>
#include <cstring>
#include <functional>
#include <random>
#include <chrono>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;

const ll INF = 1e18;
const int INFi = 2e9;
const int maxN = 1e6;
const int md2 = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    int n; cin >> n;
    vector<vector<int>> a(1, vector<int> (n));
    range(i, n) cin >> a[0][i];
    int x = 0;
    ll ans = 0;
    for(int b = 30; b >= 0; --b) {
        vector<vector<int>> nxt;
        int bt = 1<<b;
        ll inv0 = 0, inv1 = 0;
        for(auto &v: a) {
            vector<int> b0, b1;
            for(auto &z: v) {
                if (z & bt) {
                    b1.push_back(z);
                    inv1 += b0.size();
                } else {
                    b0.push_back(z);
                    inv0 += b1.size();
                }
            }
            if (!b0.empty()) nxt.push_back(b0);
            if (!b1.empty()) nxt.push_back(b1);
        }
        if (inv1 < inv0) x ^= bt;
        ans += min(inv1, inv0);
        swap(nxt, a);
    }
    cout << ans << " " << x << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}