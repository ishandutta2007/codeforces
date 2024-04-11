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
const int maxN = 1e5 + 1;
const int md2 = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

struct fenwick {
    int n{};
    vector<ll> fenw{};

    void build(int k) {
        n = k;
        fenw.resize(n);
    }

    void upd(int i, ll x) {
        for (; i < n; i = i | (i + 1)) fenw[i] += x;
    }

    ll get(int i) {
        ll res = 0;
        for (; i >= 0; i = (i & (i + 1)) - 1) res += fenw[i];
        return res;
    }

    ll get(int l, int r) {
        if (l > r) return 0;
        return get(r) - get(l - 1);
    }
};


void solve() {
    int n, k;
    cin >> n >> k;
    ll ans = 0;
    vector<ar<int, 3>> a;
    range(i, n) {
        ar<int, 3> bb;
        range(j, 3) cin >> bb[j];
        if (i && bb[0] == a.back()[0] && bb[1] == a.back()[1]) {
            a.back()[2] += bb[2];
            continue;
        }
        a.push_back(bb);
    }
    n = a.size();
    vector<int> minval(n + 1, k);
    minval[n] = 0;
    int prev = 1e9 + 5;
    bool bad = false;

    auto check = [&](int i, int prevv) {
        if (a[i][1] == prevv) {
            if (a[i][0] == a[i][1]) {
                return (ll) (minval[i + 1] + a[i][2]);
            }
            ll x = k - minval[i + 1] + 1ll * k * (a[i][1] - a[i][0] - 1);
            return (ll)(a[i][2] - x);
        }
        ll x = 1ll * k * (a[i][1] - a[i][0]);
        //cout << x << "\n";
        return (ll)(a[i][2] - x);
    };
    for (int i = n - 1; i >= 0; --i) {
        ll r = max(0ll, check(i, prev));
        if (r >= k + 1) {
            cout << "-1\n";
            return;
        }
        minval[i] = r;
        prev = a[i][0];
    }
    ll ost = k;
    range(i, n) {
        ans += a[i][2];
        if (minval[i] > ost) {
            ans += ost;
            ost = k;
        }
        ost = (k - (a[i][2] - ost) % k) % k;
    }
    cout << ans << "\n";
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