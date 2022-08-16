#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 3e5+10, MOD = 1e9+7;

int qry(string s) {
    cout << "? " << s << endl;
    int ans; cin >> ans;
    return ans;
}
void solve() {
    int n, m; cin >> n >> m;
    vector<pair<int, int>> ed;
    for (int i = 0; i < m; i++) {
        string s(m, '0'); s[i] = '1';
        ed.emplace_back(qry(s), i);
    }
    sort(ed.begin(), ed.end());
    // simulate MST
    ll ans = 0;
    string use(m, '0');
    for (int i = 0; i < m; i++) {
        ans += ed[i].first; use[ed[i].second] = '1';
        int c = qry(use);
        if (c != ans) {
            ans -= ed[i].first;
            use[ed[i].second] = '0';
        }
    }
    cout << "! " << ans << endl;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}