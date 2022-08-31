#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 3e5+10, MOD = 1e9+7;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n); for (auto& x : a) cin >> x;
    vector<int> d(n); for (auto& x : d) cin >> x;

    auto two = [&]() {
        ll ans = std::accumulate(a.begin(), a.end(), 0LL);
        ll best = MOD;
        for (int i = 0; i < n-1; i++) best = min(best, (long long) d[i]);
        return max(0LL, ans - best);
    };
    auto zero = [&]() {
        vector<ll> suf(n + 1);
        for (int i = n-1; i >= 0; i--) {
            suf[i] = a[i] + suf[i+1];
        }
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, suf[i] - d[i]);
        }
        return ans;
    };
    auto one = [&]() {
        vector<ll> suf(n + 1), pre(n);
        for (int i = n-1; i >= 0; i--) {
            suf[i] = a[i] + suf[i+1];
        }
        for (int i = 0; i < n; i++) {
            pre[i] = a[i];
            if (i) pre[i] += pre[i-1];
        }
        ll ans = 0;
        ll use = MOD;
        for (int i = 0; i < n-1; i++) {
            use = min(use, (long long) d[i]);
            ll cur = pre[i] - use + max(0LL, suf[i + 1] - d[i + 1]);
            ans = max(ans, cur);
        }
        ll best = -MOD;
        for (int i = 0; i < n-2; i++) {
            best = max(best, (long long) suf[i] - d[i]);
            ans = max(ans, best - a[i+1]);
            /*
            for (int j = 0; j <= i; j++) {
                ans = max(ans, suf[j] - a[i+1] - d[j]);
            }
            */
        }
        for (int i = 1; i < n; i++) {
            ans = max(ans, suf[i] - d[i]);
        }
        return ans;
    };

    if (k == 0) cout << zero() << '\n';
    else if (k == 1) cout << one() << '\n';
    else cout << max(zero(), two()) << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}

// 0 -> 1 -> 2 -> 3 -> 4
// 0 -> 1 -> 2 -> 3 -> 0      4
// 3 -> 0 -> 1 -> 2 -> 4
//
//
// if k >= 2:
//    answer is sum{A} - min activation cost of 1..n-1
// if k == 0:
//    bf which one you activate
// if k == 1:
//    use k = 0 or bf which one you change E_i to 0