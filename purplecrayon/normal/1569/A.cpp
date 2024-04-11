#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 15, MOD = 1e9+7;

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    for (int i = 0; i+1 < n; i++) {
        if (s[i] != s[i+1]) {
            cout << i+1 << ' ' << i+2 << '\n';
            return;
        }
    }
    cout << -1 << ' ' << -1 << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}