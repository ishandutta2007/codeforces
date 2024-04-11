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

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < (n); ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;

// using namespace __gnu_pbds;
/*
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
*/

const ll INF = 1e18;
const int INFi = 2e9;
const int maxN = 2e5 + 1;
const int md2 = 998244353;
const int md3 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

ar<ll, 3> gcd(ll a, ll b) {
    if (a == 0) {
        return {b, 0, 1};
    }
    auto[g, x1, y1] = gcd(b % a, a);
    return {g, y1 - (b / a) * x1, x1};
}

inline void shift_solution(ll &x, ll &y, ll &a, ll &b, ll cnt) {
    x += cnt * b;
    y -= cnt * a;
}

ll G, X, Y;

ll solve(ll a, ll b, ll x, ll y, ll maxx, ll miny, ll lx1, ll rx2) {
    if (lx1 > maxx) return 0;

    shift_solution(x, y, a, b, (maxx - x) / b);
    if (x > maxx) shift_solution(x, y, a, b, -1);
    ll rx1 = x;

    shift_solution(x, y, a, b, -(miny - y) / a);
    if (y < miny) shift_solution(x, y, a, b, -1);
    if (y > 0) return 0;
    ll lx2 = x;

    /*shift_solution(x, y, a, b, -(0 - y) / a);
    if (y > 0) shift_solution(x, y, a, b, 1);
    ll rx2 = x;*/

    if (lx2 > rx2) swap(lx2, rx2);

    ll rx = min(rx1, rx2);
    ll lx = max(lx1, lx2);

    return max(0ll, (rx - lx) / abs(b) + 1);
}

ll get_rx2(ll a, ll b, ll x, ll y) {
    shift_solution(x, y, a, b, -(0 - y) / a);
    if (y > 0) shift_solution(x, y, a, b, 1);
    return x;
}

ll get_lx1(ll a, ll b, ll x, ll y) {
    shift_solution(x, y, a, b, (0 - x) / b);
    if (x < 0) shift_solution(x, y, a, b, 1);
    return x;
}

void solve() {
    int n, m;
    ll k;
    cin >> n >> m >> k;
    int mx = 2 * max(n, m) + 1;
    vector<int> pos1(mx, -1), pos2(mx, -1);
    range(i, n) {
        int x;
        cin >> x;
        pos1[x] = i;
    }
    range(i, m) {
        int x;
        cin >> x;
        pos2[x] = i;
    }
    int c = 0;
    auto[g1, x1, y1] = gcd((ll) n, (ll) m);
    G = g1;
    X = x1;
    Y = y1;
    ll A = n / G;
    ll B = m / G;
    vector<ar<ll, 2>> kek(mx);
    vector<ll> lx(mx), rx(mx);
    range(i, mx) {
        if (pos1[i] == -1 || pos2[i] == -1) continue;
        ll C = pos2[i] - pos1[i];
        if (C % G != 0) continue;
        pos1[c] = pos1[i];
        pos2[c] = pos2[i];
        kek[c][0] = X * (C / G);
        kek[c][1] = Y * (C / G);
        lx[c] = get_lx1(A, B, kek[i][0], kek[i][1]);
        rx[c] = get_rx2(A, B, kek[i][0], kek[i][1]);
        c++;
    }
    mx = c;
    pos1.resize(mx);
    pos2.resize(mx);
    kek.resize(mx);

    ll L = max(-1ll, k - 2), R = 5e17 + 5;
    while (R - L > 1) {
        ll mid = (L + R) / 2;
        ll res = mid + 1;
        range(i, mx) {
            if (res < k) {
                break;
            }
            if (pos1[i] > mid || pos2[i] > mid) continue;
            res -= solve(A, B, kek[i][0], kek[i][1], (mid - pos1[i]) / n,
                         -((mid - pos2[i]) / m), lx[i], rx[i]);
        }
        if (res >= k) {
            R = mid;
        } else {
            L = mid;
        }
    }
    cout << R + 1 << "\n";
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