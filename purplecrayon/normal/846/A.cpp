#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 5e5+10, MOD = 998244353;

void solve() {
    int n; cin >> n;
    vector<int> a(n); for (auto& x : a) cin >> x;
    vector<int> pre(n), suff(n);
    for (int i = 0; i < n; i++) {
        pre[i] = a[i] ^ 1;
        suff[i] = a[i];
    }
    for (int i = 1; i < n; i++) pre[i] += pre[i-1];
    for (int i = n-2; i >= 0; i--) suff[i] += suff[i+1];
    int ans = max(pre[n-1], suff[0]);
    for (int i = 1; i < n; i++) ans = max(ans, pre[i-1] + suff[i]);
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    // cin >> T;
    while (T--) solve();
}