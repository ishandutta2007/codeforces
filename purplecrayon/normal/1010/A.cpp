#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1e5+10, MOD = 1e9+7;

int n, m, a[MAXN], b[MAXN];

void solve(){
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] <= 1) {
            cout << -1 << '\n';
            return;
        }
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        if (b[i] <= 1) {
            cout << -1 << '\n';
            return;
        }
    }
    double ans = m; 
    ans += ans / (a[0] - 1);
    for (int i = n-1; i > 0; i--) {
        ans += ans / (b[i] - 1);
        ans += ans / (a[i] - 1);
    }
    ans += ans / (b[0] - 1);
    ans -= m;
    cout << fixed << setprecision(10) << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}