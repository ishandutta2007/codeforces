#include "bits/stdc++.h"
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1e5+10, MOD = 1e9+7;

const string imp = "Impossible\n";

ll f(ll x){ return x*(x-1)/2; }
void solve(){
    int n; ll k; cin >> n >> k;
    if (k > f(n)) { cout << imp; return; }

    string ans;
    for (int i = 0; i < n; i++)  {
        ans.push_back('(');

        if (k < n-i-1) ans.push_back(')');
        else k -= n-i-1;
    }
    if (k){ cout << imp << '\n'; }
    for (int i = sz(ans); i < 2*n; i++) ans.push_back(')');
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}