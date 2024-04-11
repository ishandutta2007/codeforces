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
    ll n;
    cin >> n;
    ll n2 = n;
    vector<ll> ans;
    ll cur = 1;
    for (ll i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            ans.push_back(i);
            n /= i;
        }
    }
    if (n != 1) ans.push_back(n);
    if (ans.size() >= 2) {
        ll ans1 = ans[0];
        ll ans2 = ans.back();
        if (ans1 == ans2 && ans.size() == 2) {
            cout << "NO\n";
            return;
        } else if (ans1 == ans2) {
            ans2 *= ans[1];
        }
        ll ans3 = n2 / ans2 / ans1;
        if (ans3 != ans1 && ans3 != ans2 && ans2 != ans3 && ans1 != 1 && ans2 != 1 && ans3 != 1) {
            cout << "YES\n";
            cout << ans1 << ' ' << ans2 << ' ' << ans3 << '\n';
            return;
        }
    }
    cout << "NO\n";
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