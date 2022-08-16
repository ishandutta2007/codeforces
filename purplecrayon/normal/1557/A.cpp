#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

void solve(){
    int n; cin >> n;
    vector<int> a(n); for (auto& c : a) cin >> c;
    sort(a.begin(), a.end());
    ll x = 0, y = 0;
    for (int i = 0; i < n-1; i++) x += a[i];
    y += a[n-1];

    double ans = double(x)/double(n-1) + double(y);
    cout << fixed << setprecision(10) << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}