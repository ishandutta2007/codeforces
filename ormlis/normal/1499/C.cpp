#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for(int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array

typedef long long ll;

using namespace std;
//using namespace __gnu_pbds;

const int INFi = 2e9 + 5;
const int maxN = 1e7 + 5;
const int md = 1e9 + 7;
const ll INF = 2e18;

void solve() {
    int n;
    cin >> n;
    vector<ll> c(n);
    range(i, n) cin >> c[i];
    vector<ll> sum(2);
    vector<ll> mn(2, INFi);
    ll ans = INF;
    range(i, n) {
        mn[i & 1] = min(mn[i & 1], c[i]);
        sum[i & 1] += c[i];
        if (i) {
            ll cur = sum[0] + sum[1];
            ll c0 = i / 2 + 1;
            ll c1 = (i + 1) - c0;
            c0 = n - c0;
            c1 = n - c1;
            cur += c0 * mn[0];
            cur += c1 * mn[1];
            ans = min(ans, cur);
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}