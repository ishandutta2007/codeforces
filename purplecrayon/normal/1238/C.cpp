#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 5e5+10, MOD = 998244353;

void solve() {
    int h, n; cin >> h >> n;
    vector<int> a(n); for (auto& x : a) cin >> x;
    a.push_back(0);
    int ans = 0;
    for (int i = 1; i < n; i++) {
        if (a[i+1] == a[i] - 1) i++;
        else ans++;
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}