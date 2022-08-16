#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1e5+10, MOD = 1e9+7;

int n, x;
ll a[MAXN];

void solve() {
    cin >> n >> x, --x;
    for (int i = 0; i < n; i++) cin >> a[i];

    ll mn = *min_element(a, a+n);
    int c = x, ops = 0;
    while (a[c] > mn) {
        a[c]--, c = (c + n - 1) % n, ops++;
    }
    for (int i = 0; i < n; i++) {
        if (i == c) cout << ops + mn * n << ' ';
        else cout << a[i] - mn << ' ';
    }
    cout << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    // cin >> T;
    while (T--) solve();
}