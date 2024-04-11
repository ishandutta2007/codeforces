#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 4e5+10, MOD = 1e9+7; 

void solve(){
    int n; cin >> n;
    string a, b; cin >> a >> b;
    vector<bool> can(n);
    int ps = 0;
    for (int i = 0; i < n; i++) {
        ps += a[i] == '1';
        if (2*ps == i+1) can[i] = 1;
    }
    bool flip = 0;
    for (int i = n-1; i >= 0; i--) {
        bool diff = bool(a[i] != b[i])^flip;
        if (diff) {
            if (!can[i]){ cout << "NO\n"; return; }
            flip ^= 1;
        }
    }
    cout << "YES\n";
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}