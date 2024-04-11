#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
using namespace std;

const ll INF = 1e18;
const int INFi = 1e9 * 2;
const int maxN = 1000001;
ll md = 1000000007;

void solve() {
    ll q, x; cin >> q >> x;
    vector<ll> xs(x, 0);
    for(ll i = 0; i < x; ++i) {
        xs[i] = i;
    }
    set<ll> se;
    range(i, x) {
        se.insert(i);
    }
    range(i, q) {
        ll f; cin >> f;
        f %= x;
        se.erase(xs[f]);
        xs[f] += x;
        se.insert(xs[f]);
        cout << *se.begin() << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests = 1;
    range(_, tests) {
        solve();
    }
    return 0;
}