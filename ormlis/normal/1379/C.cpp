#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;

using namespace std;


const ll INF = 1e18;
const int INFi = 2e9;
const int maxN = 1e5 + 5;
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

void solve() {
    int m, n; cin >> m >> n;
    vector<pair<int, int>> a(n);
    range(i, n) cin >> a[i].first >> a[i].second;
    sort(all(a));
    vector<ll> suf(n+1);
    suf[n] = 0;
    suf[n-1] = a[n-1].first;
    for(int i = n - 2; i >= 0; --i) suf[i] = suf[i+1] + a[i].first;
    ll ans = 0;
    range(i, n) {
        ll res = 0;
        pair<int, int> kek = {a[i].second, -1};
        int l = lower_bound(all(a), kek) - a.begin();
        l = max(l, n - m);
        int cnt = n - l;
        res += suf[l];
        if (i < l && cnt < m) {
            cnt++;
            res += a[i].first;
        }
        res += 1ll * a[i].second * (m - cnt);
        ans = max(ans, res);
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //cout << setprecision(15) << fixed;
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}