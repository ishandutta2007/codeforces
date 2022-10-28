#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

ll rnd() {
    return uniform_int_distribution<long long>(0, LLONG_MAX / 2)(rng);
}
int n, k, a[MAXN], b[MAXN];
ll h[MAXN];
char ans[MAXN];

void solve() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i], --a[i];
    for (int i = 0; i < n; i++) cin >> b[i], --b[i];
    for (int i = 0; i < n; i++) h[i] = rnd();
    ll x = 0, y = 0;
    int c = 0;
    for (int i = 0; i < n; i++) {
        x ^= h[a[i]], y ^= h[b[i]];
        ans[a[i]] = ans[b[i]] = char('a' + c);
        if (i < n-1 && x == y) {
            c = min(25, c + 1);
            x = 0, y = 0;
        }
    }
    if (c + 1 < k) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++) cout << ans[i];
    cout << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    // cin >> T;
    while (T--) solve();
}