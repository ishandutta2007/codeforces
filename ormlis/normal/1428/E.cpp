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
const int maxN = 2e5 + 1;
const int md2 = 998244353;
const int md3 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    range(i, n) cin >> a[i];
    sort(rall(a));
    ll ans = 0;
    vector<ll> changes;
    auto get_s = [&](int cnt, int i) {
        int s1 = a[i] / cnt;
        int s2 = a[i] / cnt + 1;
        int cnt2 = a[i] % cnt;
        int cnt1 = cnt - cnt2;
        ll cur2 = 1ll * s1 * s1 * cnt1;
        cur2 += 1ll * s2 * s2 * cnt2;
        return cur2;
    };
    vector<int> answ(n);
    vector<ll> cur(n);
    set<pair<ll, int>> s;
    range(i, n) {
        answ[i] = 1;
        cur[i] = get_s(answ[i], i);
        ans += cur[i];
        if (a[i] >= 2) s.insert({get_s(2, i) - cur[i], i});
    }
    int need = k - n;
    range(_, need) {
        auto p = *s.begin();
        s.erase(s.begin());
        ans += p.first;
        answ[p.second]++;
        cur[p.second] += p.first;
        if (a[p.second] >= answ[p.second] + 1) {
            s.insert({get_s(answ[p.second] + 1, p.second) - cur[p.second], p.second});
        }
    }
    cout << ans;
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