#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

void solve() {
    int n; cin >> n;
    const int B = 30;
    vector<bool> has(B);
    while (n--) {
        int x; cin >> x;
        for (int i = 0; i < B; i++) if ((x >> i) & 1)
            has[i] = true;
    }
    int ans = 0;
    for (int i = 0; i < B; i++) if (has[i]) ans |= 1 << i;
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}