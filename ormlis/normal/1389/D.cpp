#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <array>
#include <set>
#include <map>
#include <random>
#include <chrono>
#include <bitset>
#include <unordered_map>
#include <unordered_set>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;
using namespace std;

const int INFi = 1e9;
const ll INF = 1e18;

void solve() {
    int n;
    ll k;
    cin >> n >> k;
    ll l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;
    ll need0 = max(0ll, max(l1 - r2, l2 - r1));
    ll inters = max(0ll, min(r1, r2) - max(l1, l2));
    ll L = min(l1, l2);
    ll R = max(r1, r2);
    ll can1 = (R - L) * 2 - (r2 - l2) - (r1 - l1) - need0;
    ll ans = INF;
    range(i, n) {
        ll shodili = 1ll * (can1 + need0) * i;
        ll current = 1ll * can1 * i + 1ll * inters * n;
        if (current >= k) {
            ans = min(ans, shodili);
            break;
        }
        shodili += need0;
        ll need1 = k - current;
        shodili += min(need1, can1);
        current += min(need1, can1);
        if (current >= k) {
            ans = min(ans, shodili);
        }
        need1 = k - current;
        shodili += need1 * 2;
        current += need1;
        if (current >= k) {
            ans = min(ans, shodili);
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}