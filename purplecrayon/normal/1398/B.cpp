#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 3e5+10, MOD = 1e9+7;

void solve() {
    string s; cin >> s;
    int n = sz(s);
    vector<int> a; a.reserve(n);
    int run = 0;
    for (int i = 0; i < n; i++) {
        run++;
        if (i == n-1 || s[i] != s[i+1]) {
            if (s[i] == '1') a.push_back(run);
            run = 0;
        }
    }
    sort(a.rbegin(), a.rend());
    int ans = 0;
    for (int i = 0; i < sz(a); i += 2) ans += a[i];
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}