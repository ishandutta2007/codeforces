#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 1e9+7;

void solve() {
    int n, q; cin >> n >> q;
    vector<int> a(n); for (auto& x : a) cin >> x;
    vector<bool> prime(n + 1, 1);
    vector<int> use; use.reserve(n);
    for (int i = 2; i <= n; i++) if (prime[i]) {
        if (n % i == 0) use.push_back(n / i);
        for (int j = 2 * i; j <= n; j += i) prime[j] = 0;
    }
    int m = sz(use);
    vector<vector<ll>> store(m);
    multiset<ll> s;
    for (int i = 0; i < m; i++) {
        store[i].resize(use[i]);
        for (int j = 0; j < use[i]; j++) {
            int c = j;
            while (c < n) {
                store[i][j] += a[c];
                c += use[i];
            }
            s.insert(store[i][j] * use[i]);
        }
    }
    cout << *s.rbegin() << '\n';
    while (q--) {
        int p, x; cin >> p >> x, --p;
        int d = x - a[p];
        for (int i = 0; i < m; i++) {
            int me = p % use[i];
            s.erase(s.find(store[i][me] * use[i]));
            store[i][me] += d;
            s.insert(store[i][me] * use[i]);
        }
        a[p] = x;
        cout << *s.rbegin() << '\n';
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}