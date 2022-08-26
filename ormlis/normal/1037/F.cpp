#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array

using namespace std;
//using namespace __gnu_pbds;


typedef long long ll;
typedef double ld;
typedef unsigned long long ull;

/*
typedef tree<
        pair<ll, int>,
        null_type,
        less<pair<ll, int>>,
        rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set;
*/

const int INFi = 1e9 + 5;
const int md = 1e9 + 7;
const ll INF = 2e18;
const int maxN = 2e6 + 1;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    range(i, n) cin >> a[i];
    vector<int> bl(n, -1), br(n, n);
    {
        vector<int> stk;
        range(i, n) {
            while (!stk.empty() && a[stk.back()] < a[i]) {
                stk.pop_back();
            }
            if (!stk.empty()) bl[i] = stk.back();
            stk.push_back(i);
        }
        stk.clear();
        for (int i = n - 1; i >= 0; --i) {
            while (!stk.empty() && a[stk.back()] <= a[i]) {
                stk.pop_back();
            }
            if (!stk.empty()) br[i] = stk.back();
            stk.push_back(i);
        }
        stk.clear();
    }
    ll ans = 0;
    auto solve = [&](int L, int R) {
        ll lk = (L + k - 2) / (k - 1);
        ll rk = (R + k - 2) / (k - 1);
        ll cnt = 0;
        if (lk == rk) {
            cnt += 1ll * (R - L + 1) * lk;
        } else {
            ll midR = (rk - 1) * (k - 1);
            ll midL = lk * (k - 1) + 1;
            if (midL <= midR) {
                // lk + 1, lk + 2, .. rk - 1
                ll A = lk + 1;
                ll B = rk - 1;
                ll res = (B - A) * (B - A + 1) / 2;
                res += A * (B - A + 1);
                res *= (k - 1);
                cnt += res;
            }
            cnt += 1ll * (midL - L) * lk;
            cnt += 1ll * (R - midR) * rk;
        }
        return cnt;
    };
    range(i, n) {
        int L = br[i] - i;
        int R = br[i] - (bl[i] + 1);
        ll cnt = solve(L, R) % md;
        cnt -= solve(0, i - (bl[i] + 1)) % md;
        ans += 1ll * (cnt - 1) * a[i];
        ans %= md;
        ans += md;
        ans %= md;
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    // cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}