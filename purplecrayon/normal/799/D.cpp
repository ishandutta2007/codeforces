#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 1e5+10, MOD = 998244353;

int pdp[N], cdp[N];

int get(int a, int b, int h, int w, vector<int> v) {
    sort(v.rbegin(), v.rend());
    while (sz(v) > 40) v.pop_back();

    int ans = 0;
    auto can = [&]() {
        for (int i = a; i < N; i++) if (pdp[i] >= b) {
            return true;
        }
        return false;
    };

    memset(pdp, 0, sizeof(pdp));
    memset(cdp, 0, sizeof(cdp));
    pdp[h] = cdp[h] = w;

    if (can()) return ans;
    for (int x : v) {
        ans++;
        for (int i = 1; i < N; i++) {
            int ni = min((long long) i * x, (long long) N - 1);
            int nj = min((long long) pdp[i] * x, (long long) N - 1);
            cdp[ni] = max(cdp[ni], pdp[i]);
            cdp[i] = max(cdp[i], nj);
        }
        for (int i = 0; i < N; i++) {
            pdp[i] = cdp[i];
        }

        if (can()) return ans;
    }
    return MOD;
}
void solve() {
    int a, b, h, w, n; cin >> a >> b >> h >> w >> n;
    vector<int> v(n); for (auto& x : v) cin >> x;
    int ans = min(get(a, b, h, w, v), get(b, a, h, w, v));
    if (ans == MOD) ans = -1;
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    // cin >> T;
    while (T--) solve();
}