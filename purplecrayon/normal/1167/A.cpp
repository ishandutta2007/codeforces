#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    for (int i = 0; i < n; i++) if (s[i] == '8') {
        if (n - i >= 11) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}