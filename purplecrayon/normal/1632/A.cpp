#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1e5+10, MOD = 1e9+7;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    if (sz(s) >= 3) {
        cout << "NO\n";
    } else if (sz(s) == 2 && s[0] == s[1]) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}