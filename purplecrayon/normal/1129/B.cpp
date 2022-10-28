#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e3+10, MOD = 1e9+7;

const int BOUND = 2e3;

void solve() {
    int k; cin >> k;

    for (int cnt = 1; cnt <= BOUND; cnt++) if (k % cnt == 0) {
        for (int len = 0; len + cnt <= BOUND; len++) {
            ll sum = k/cnt + cnt*cnt + len;
            const int MAX = 1e6;
            if (sum <= (long long) len * MAX) {
                cout << cnt+len << '\n';
                for (int i = 0; i < cnt; i++) cout << -1 << ' ';
                for (int i = 0; i < len; i++) {
                    ll c = min(sum, (long long) MAX);
                    sum -= c;
                    cout << c << ' ';
                }
                cout << '\n';
                return;
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}