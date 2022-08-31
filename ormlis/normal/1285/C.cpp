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

ll ans = INF;
vector<ll> divisors;
vector<pair<ll, int>> p;

ll get(ll num ,int pos) {
    if (pos == p.size()) {
        divisors.push_back(num);
    } else {
        get(num * pow(p[pos].first, p[pos].second), pos +1 );
        get(num, pos + 1);
    }
}

void solve() {
    ll x; cin >> x;
    ll x3 = x;
    for(ll i = 2; i * i <= x; ++i) {
        if (x % i == 0) p.emplace_back(i, 0);
        while(x % i == 0) {
            p.back().second++;
            x /= i;
        }
    }
    if (x != 1) p.emplace_back(x, 1);
    get(1, 0);
    for(auto x2: divisors) {
        ans = min(max(x2, x3 / x2), ans);
    }
    cout << x3 / ans << ' '  << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests;
    tests = 1;
    range(_, tests) {
        solve();
    }
    return 0;
}