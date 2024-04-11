#include "bits/stdc++.h"
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 5e5+10, MOD = 1e9+7;

const string yes = "YES\n", no = "NO\n";
void solve(){
    int x1, y1, x2, y2, x3, y3; cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    cout << 3 << '\n' << x1+x2-x3 << ' ' << y1+y2-y3 << '\n' << x1-x2+x3 << ' ' << y1-y2+y3 << '\n' << x2+x3-x1 << ' ' << y2+y3-y1 << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}