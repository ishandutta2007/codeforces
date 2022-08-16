#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 5e5+10, MOD = 1e9+7;

void solve() {
    int n; cin >> n;
    int cnt[2]={};
    while (n--) {
        int x; cin >> x;
        if (x > 1) continue;
        cnt[x]++;
    }
    ll ans = (1LL << cnt[0]) * cnt[1];
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}