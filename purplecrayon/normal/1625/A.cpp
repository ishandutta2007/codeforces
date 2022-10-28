#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1e6+10, MOD = 998244353;

void solve() {
    int n, l; cin >> n >> l;
    vector<int> cnt(l);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        for (int b = 0; b < l; b++) if ((x >> b) & 1)
            cnt[b]++;
    } 
    int ans = 0;
    for (int b = 0; b < l; b++) {
        if (cnt[b] > n - cnt[b])
            ans |= 1 << b;
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}