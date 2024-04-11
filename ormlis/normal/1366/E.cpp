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
#include <cassert>
#include <iomanip>
// #include <ext/pb_ds/assoc_container.hpp>

// using namespace __gnu_pbds;

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
const int maxN = 1e7 + 1;
const int md = 998244353;
const int md3 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> a(n);
    vector<int> b(m);
    range(i, n) {
        cin >> a[i].first;
        a[i].second = i;
    }
    b.push_back(INFi);
    range(i, m) cin >> b[i];
    sort(all(a));
    vector<pair<int, int>> res;
    int j = 0;
    range(i, m) {
        if (a[j].first != b[i]) {
            cout << "0\n";
            return;
        }
        int l = -1;
        int r = -1;
        while (j < n && b[i + 1] > a[j].first) {
            if (a[j].first == b[i]) l = a[j].second;
            r = max(r, a[j].second);
            j++;
        }
        res.emplace_back(l, r);
    }
    int ans = 1;
    for(int i = 0; i + 1 < m; ++i) {
        if (res[i+1].first <= res[i].second) {
            cout << "0\n";
            return;
        }
        ans = (1ll * ans * (res[i+1].first - res[i].second)) % md;
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    // cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}