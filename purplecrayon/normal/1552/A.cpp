#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    string t = s;
    sort(t.begin(), t.end());

    int ans = 0;
    for (int i = 0; i < n; i++) if (t[i] != s[i]) ans++;
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}