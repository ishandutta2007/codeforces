#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

void solve() {
    int n; cin >> n;
    vector<ll> b(n); for (auto& x : b) cin >> x;
    if (n == 1) {
        cout << "YES\n";
        cout << b[0] << '\n';
        return;
    }
    vector<ll> x(n);
    for (int i = 0; i < n; i++) {
        x[i] = b[i] - b[(i - 1 + n) % n];
    }
    vector<ll> p(n);
    for (int i = 0; i < n; i++) {
        p[i] = x[i] - x[(i - 1 + n) % n];
        p[i] *= -1;
        if (p[i] % n) {
            cout << "NO\n";
            return;
        }
        p[i] /= n;
    }
    if (std::accumulate(p.begin(), p.end(), 0LL) != 0) {
        cout << "NO\n";
        return;
    }
    ll sum = 0;
    for (int i = 1; i < n; i++) {
        int occ = n - i;
        sum += p[i] * occ * (occ + 1) / 2;
    }
    ll one = b[n-1] - sum;
    if (one % ((long long) n * (n + 1) / 2)) {
        cout << "NO\n";
        return;
    }
    one /= n * (n + 1) / 2;
    vector<ll> a(n);
    a[0] = one;
    for (int i = 1; i < n; i++) a[i] = a[i-1] + p[i];
    for (int i = 0; i < n; i++) {
        if (a[i] <= 0 || a[i] > int(1e9)) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    for (ll x : a) cout << x << ' ';
    cout << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}