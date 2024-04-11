#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1e5+10, MOD = 1e9+7;

int n, m, a[MAXN];
vector<int> nxt[MAXN];

void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) cin >> a[i], --a[i];
    for (int i = 0; i < m; i++) {
        for (int j : {i-1, i+1}) if (0 <= j && j < m) {
            if (a[i] != a[j])
                nxt[a[i]].push_back(a[j]);
        }
    }
    ll cur = 0;
    for (int i = 1; i < m; i++) {
        cur += abs(a[i]-a[i-1]);
    }
    ll ans = cur;
    for (int i = 0; i < n; i++) if (sz(nxt[i])) {
        int N = sz(nxt[i]);
        sort(nxt[i].begin(), nxt[i].end());
        int m = nxt[i][N/2];

        ll me = 0;
        for (auto c : nxt[i]) {
            me -= abs(c-i);
            me += abs(c-m);
        }
        assert(me <= 0);
        ans = min(ans, cur + me);
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    // cin >> T;
    while (T--) solve();
}