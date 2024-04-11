#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

const int MAXV = 1e6+10;
int pf[MAXV];

void pre() {
    memset(pf, -1, sizeof(pf));
    for (int i = 2; i < MAXV; i++) if (pf[i] == -1) {
        for (int j = i; j < MAXV; j+=i) pf[j] = i;
    }
}

void solve() {
    int n, e; cin >> n >> e;
    vector<int> a(n); for (auto& c : a) cin >> c;
    vector<int> l(n), r(n);
    for (int i = 0; i < n; i++) {
        if (a[i] == 1) l[i] = 1 + (i >= e ? l[i-e] : 0);
        else l[i] = 0;
    }
    for (int i = n-1; i >= 0; i--) {
        if (a[i] == 1) r[i] = 1 + (i + e < n ? r[i+e] : 0);
        else r[i] = 0;
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) if (a[i] > 1 && pf[a[i]] == a[i]) {
        ll one = (i >= e ? l[i-e] : 0);
        ll two = (i+e < n ? r[i+e] : 0);
        ans += (long long) (one + 1) * (two + 1) - 1;
    }
    cout << ans << '\n';
}
int main(){
    pre();

    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}