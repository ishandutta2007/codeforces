#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 3e5+10, MOD = 1e9+7;

void solve() {
    int n, a, b; cin >> n >> a >> b;
    string s; cin >> s;
    int ans = a * n;
    if (b < 0) {
        int cnt = 1;
        for (int i = 1; i < n; i++) cnt += s[i] != s[i-1];
        if (cnt == 1) ans += b;
        else ans += b * ((cnt + 2) / 2);
    } else {
        ans += b * n;
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}