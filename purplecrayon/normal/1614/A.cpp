#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 5e5+10, MOD = 1e9+7;

void solve() {
    int n, l, r, k; cin >> n >> l >> r >> k;
    vector<int> v;
    while (n--) {
        int x; cin >> x;
        if (l <= x && x <= r) v.push_back(x);
    }
    sort(v.begin(), v.end());
    ll sum = 0;
    int ans = 0;
    for (int x : v) {
        sum += x;
        if (sum <= k) ans++;
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}