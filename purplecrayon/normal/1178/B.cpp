#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

void solve() {
    string s; cin >> s;
    int n = sz(s);

    vector<int> one(n-1), two(n-1);
    for (int i = 0; i < n-1; i++) {
        if (s[i] == 'v' && s[i+1] == 'v') one[i]++, two[i]++;
    }
    for (int i = 1; i < sz(one); i++) one[i] += one[i-1];
    for (int i = sz(two)-2; i >= 0; i--) two[i] += two[i+1];
    ll ans = 0;
    for (int i = 1; i < n-2; i++) if (s[i] == 'o') {
        ll x = one[i-1], y = two[i+1];
        ans += x * y;
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    // cin >> T;
    while (T--) solve();
}