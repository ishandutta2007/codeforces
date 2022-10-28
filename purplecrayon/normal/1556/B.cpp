#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

void solve(){
    int n; cin >> n;
    vector<int> a(n); for (auto& it : a) cin >> it;
    vector<int> x, y, has;
    for (int i = 0; i < n; i++) {
        if (i&1) x.push_back(i);
        else y.push_back(i);

        if (a[i]&1) has.push_back(i);
    }
    auto get = [&](vector<int> b) -> ll {
        if (sz(b) != sz(has)) return -1;
        ll ans = 0;
        for (int i = 0; i < sz(b); i++) ans += abs(b[i]-has[i]);
        return ans;
    };

    ll v1 = get(x), v2 = get(y);
    if (v1 == -1) cout << v2 << '\n';
    else if (v2 == -1) cout << v1 << '\n';
    else cout << min(v1, v2) << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}