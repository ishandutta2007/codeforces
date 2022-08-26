#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;

using namespace __gnu_pbds;
using namespace std;

const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 4e5 + 1;
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    int n, q;
    cin >> n >> q;
    vector<ll> cnt_init(n);
    range(i, n) cin >> cnt_init[i];
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int i, v;
            cin >> i >> v;
            cnt_init[i] = v;
            continue;
        }
        int i;
        ll k;
        cin >> i >> k;
        ll st2 = 2;
        ll ans = 0;
        auto cnt = cnt_init;
        range(j, i + 1) k -= cnt[j];
        if (k <= 0) {
            cout << "0\n";
            continue;
        }
        for (int j = i + 1; j < n; ++j) {
            ll x = min(k / st2, cnt[j]);
            k -= st2 * x;
            ans += (st2 - 1) * x;
            cnt[j] -= x;
            cnt[i] += st2 * x;
            st2 *= 2;
        }
        ll can1 = 0;
        st2 = 2;
        for (int j = 1; j <= i; ++j) {
            can1 += (st2 - 1) * cnt[j];
            cnt[0] += st2 * cnt[j];
            cnt[j] = 0;
            st2 *= 2;
        }
        if (k <= can1) {
            cout << ans + k << "\n";
            continue;
        }
        //k -= can1;
        //ans += can1;
        int j = i + 1;
        st2 = 2;
        while (j < n && !cnt[j]) {
            st2 *= 2;
            j++;
        }
        if (j == n) {
            cout << "-1\n";
            continue;
        }
        ans++;
        j--;
        if (j == i) {
            k -= 2;
        }
        st2 /= 2;
        ll sti = 1;
        range(_, i) sti *= 2;
        while (j != i) {
            if (st2 <= k) {
                ans += st2 - 1;
                k -= st2;
                if (k == 0) break;
                can1 += st2 * (sti - 1);
                if (can1 >= k) break;
            }
            ans++;
            st2 /= 2;
            j--;
            if (j == i) {
                k -= 2;
            }
        }
        cout << ans + max(k, 0ll) << '\n';
    }
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