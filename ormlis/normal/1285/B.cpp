#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

using namespace std;

typedef long long ll;

const ll INF = 1e18;
const int INFi = 1e9 * 2;
const int maxN = 100001;
ll md = 998244353;

void solve() {
    int n; cin >> n;
    vector<ll> a(n);
    range(i, n) cin >> a[i];
    ll curmin = 0;
    ll cur = 0;
    ll ans = -INF;
    int flag = 0;
    range(i, n) {
        cur += a[i];
        if (!flag && i == n - 1) continue;
        ans = max(ans, cur - curmin);
        if (cur <= curmin) {curmin = cur; flag = 1;}
    }
    if (ans < cur) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}