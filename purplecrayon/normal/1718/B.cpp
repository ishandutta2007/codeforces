#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 1e9+7;

void solve() {
    int n; cin >> n;
    vector<int> a(n); for (auto& x : a) cin >> x;

    ll sum = 0;
    for (int x : a) sum += x;
    if (sum == 1) {
        cout << "YES\n";
        return;
    }

    vector<ll> fib{1, 1};
    ll sum_fib = 2;
    while (sum_fib < sum) {
        fib.push_back(fib.end()[-1] + fib.end()[-2]);
        sum_fib += fib.back();
    }
    if (sum_fib != sum) {
        cout << "NO\n";
        return;
    }
    int last = -1;
    while (sz(fib)) {
        ll x = fib.back();
        
        pair<int, int> cur{0, -1};
        for (int i = 0; i < n; i++) if (i != last) 
            cur = max(cur, {a[i], i});

        if (cur.first < x) {
            cout << "NO\n";
            return;
        }

        a[cur.second] -= x;
        last = cur.second;

        fib.pop_back();
    }
    cout << "YES\n";
    return;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}