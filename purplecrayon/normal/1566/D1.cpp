#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

void solve() {
    int n, m; cin >> n >> m;
    assert(n == 1);
    vector<int> a(m); for (auto& c : a) cin >> c;
    vector<int> p(m); iota(p.begin(), p.end(), 0);
    sort(p.begin(), p.end(), [&](int i, int j){ 
        if (a[i] != a[j]) return a[i] < a[j];
        return i > j;
    });
    vector<int> loc(m);
    for (int i = 0; i < m; i++) loc[p[i]] = i;
    vector<bool> bad(m);

    int ans = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j <= loc[i]; j++) ans += bad[j];
        bad[loc[i]] = 1;
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}