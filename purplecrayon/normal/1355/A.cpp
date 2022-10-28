#include <bits/stdc++.h>
using namespace std;

#define sz(v) (int)v.size()

typedef vector<int> vi;
typedef long long ll;
const int MAXN = 3e5+10, MAXM = 3e5+10, MAXL = 21;
const string yes = "YES\n", no = "NO\n";



void solve(){
    ll n, k; cin >> n >> k;
    ll ans = n;
    for (int i = 2; i <= k; i++){
        string s = to_string(ans);
        int mn=10, mx=-1;
        for (auto c : s) mn = min(mn, c-'0'), mx = max(mx, c-'0');
        if (mn == 0) { break; }
        ans = ans + mn*mx;
    }
    cout << ans << "\n";
}
int main(){
    ios::sync_with_stdio(false); cin.sync_with_stdio(false); cin.tie(0);
    int t=1;
    cin >> t;
    while (t--) solve();
}