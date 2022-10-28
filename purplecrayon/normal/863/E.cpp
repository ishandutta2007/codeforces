#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

void solve(){
    int n; cin >> n;
    vector<ar<int, 2>> a(n); for (auto& c : a) cin >> c[0] >> c[1];

    map<int, vector<ar<int, 2>>> ev;
    for (int i = 0; i < n; i++) {
        auto c = a[i];
        ev[c[0]].push_back({i, +1});
        ev[c[1]+1].push_back({i, -1});
    }
    vector<bool> bad(n);

    set<int> act;
    for (auto c : ev) {
        auto v = c.second;

        for (auto e : v) {
            if (e[1] == +1) act.insert(e[0]);
            else act.erase(e[0]);
        }
        if (sz(act) == 1) {
            bad[*act.begin()] = 1;
        }
    }
    for (int i = 0; i < n; i++) if (!bad[i]) { cout << i+1 << '\n'; return; }
    cout << -1 << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}