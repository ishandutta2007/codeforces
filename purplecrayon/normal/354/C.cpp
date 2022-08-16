#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 3e5+10, MOD = 998244353;

const int MAXA = 1e6+10;

int n, k, a[MAXN], mn = MAXA;
bool has[2*MAXA];
int low[2*MAXA];

void solve(){
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i], has[a[i]] = 1, mn = min(mn, a[i]);
    int c = -1;
    for (int i = 1; i < 2*MAXA; i++) {
        low[i] = c;
        if (has[i]) c = i;
    }
    int ans = 1;
    for (int g = 2; g <= mn; g++) {
        bool bad = 0;
        for (int d = g; d < MAXA; d += g) {
            if (low[d+g] >= d && low[d+g]-d > k) {
                bad = 1;
                break;
            }
        }
        if (bad) continue;
        ans = max(ans, g);
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}