#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

void solve() {
    string s; cin >> s;
    int cnt[2]={};
    for (auto c : s) cnt[c-'0']++;
    if (!cnt[0]) {
        cout << 0 << '\n';
        return;
    }
    int n = sz(s);
    int mn = n, mx = -1;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') mn = min(mn, i), mx = max(mx, i);
    }
    if (mx-mn+1 == cnt[0]) cout << 1 << '\n';
    else cout << 2 << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}