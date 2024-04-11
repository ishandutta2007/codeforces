#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
using namespace std;

const ll INF = 1e18;
const int INFi = 1e9 * 2;
const int maxN = 100001;
ll md = 1000000007;
vector<pair<ll, int>> d;
ll ans, curm;

void calc(ll a, ll cur, int pos, int su) {
    if (pos == d.size()) {
        if (cur != 1) {
            if (su % 2) {
                ans -= (a + curm - 1) / cur - (a - 1) / cur;
            } else {
                ans += (a + curm - 1) / cur - (a - 1) / cur;
            }
        }
        return;
    }
    calc(a, cur, pos + 1, su);
    calc(a, cur * d[pos].first, pos + 1, su + 1);
}

void solve() {
    d.clear();
    ll a, m;
    cin >> a >> m;
    ll g = __gcd(a, m);
    a /= g;
    m /= g;
    ans = m;
    curm = m;
    for (ll i = 2; i * i <= m; ++i) {
        while (m % i == 0) {
            if (!d.empty() && d.back().first == i) d.back().second++;
            else d.emplace_back(i, 1);
            m /= i;
        }
    }
    if (m != 1) {
        d.emplace_back(m, 1);
    }
    calc(a, 1, 0, 0);
    cout << ans << '\n';
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