#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

ll get(ll x) {
    int ans = 0;
    for (char c : to_string(x)) ans += c-'0';
    return ans;
}
void solve(){
    ll x; cin >> x;
    cout << (x+1)/10 << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}