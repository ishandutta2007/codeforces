#include <bits/stdc++.h>
using namespace std;

#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

const int INF = 1e9+10;

int n, x[MAXN];
int ans = INF;

void solve() {
    cin >> n; n *= 2;
    for (int i = 0; i < n; i++) cin >> x[i];
    sort(x, x+n);
    for (int a = 0; a < n; a++) for (int b = 0; b < n; b++) {
        int c = -1, cur = 0;
        for (int i = 0; i < n; i++) if (i != a && i != b) {
            if (c == -1) c = x[i];
            else cur += abs(c-x[i]), c = -1;
        }
        ans = min(ans, cur);
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}