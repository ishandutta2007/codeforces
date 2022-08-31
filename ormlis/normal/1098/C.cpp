#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array
using namespace std;

/*
using namespace __gnu_pbds;

typedef tree<
        pair<int, int>,
        null_type,
        less<pair<int, int>>,
        rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set;
*/

typedef long long ll;
typedef double ld;
typedef unsigned long long ull;

const int INFi = 1e9 + 5;
const int md = 1e9 + 7;
const ll INF = 2e18;
const int maxN = 2e6 + 1;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    int n;
    cin >> n;
    vector<int> p(n + 1);
    vector<int> h(n + 1);
    ll s;
    cin >> s;
    auto check = [&](int x) {
        ll cur = 0;
        h[1] = 0;
        h[0] = 0;
        int can = 1;
        int to = 0;
        for (int cnt = 1; cnt < n; ++cnt) {
            h[cnt] = h[to] + 1;
            p[cnt] = to;
            can--;
            if (can == 0) {
                to++;
                can = x;
            }
            int mx = h[cnt];
            cur += h[cnt];
            if (cur > s) continue;
            ll cur2 = cur;
            if (cnt + 1 < n) {
                ll A = mx + 1;
                ll B = mx + (n - 1) - cnt;
                cur2 += (B - A) * (B - A + 1) / 2;
                cur2 += A * (B - A + 1);
            }
            if (cur2 > s) continue;
            ll ost = s - cur2;
            if (ost < mx + 1 || ost > mx + (n - cnt)) continue;
            if (ost == mx + 1) {
                p[n] = cnt;
            }
            for (int j = cnt + 1; j < n; ++j) {
                h[j] = h[j - 1] + 1;
                p[j] = j - 1;
                if (h[j] + 1 == ost) {
                    p[n] = j;
                }
            }
            return true;
        }
        p[n] = to;
        cur += h[to] + 1;
        if (cur == s) return true;
        return false;
    };
    ll t = 1ll * n * (n + 1) / 2;
    if (t == s) {
        cout << "Yes\n";
        for (int i = 1; i < n; ++i) cout << i << ' ';
        cout << '\n';
        return;
    }
    if (t < s) {
        cout << "No\n";
        return;
    }
    int L = 1, R = n;
    while(R - L > 1) {
        int mid = (R + L) / 2;
        if (check(mid)) {
            R = mid;
        } else {
            L = mid;
        }
    }
    if (!check(R)) {
        cout << "No\n";
        return;
    }
    cout << "Yes\n";
    for(int i = 2; i <= n; ++i) cout << p[i] << ' ';
    cout << '\n';
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