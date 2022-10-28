#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

void solve(){
    int c, d; cin >> c >> d;
    if ((c+d)%2) cout << -1 << '\n';
    else if (c == 0 && d == 0) cout << 0 << '\n';
    else if (c == d || c == -d) cout << 1 << '\n';
    else cout << 2 << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}