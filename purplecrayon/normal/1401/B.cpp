#include <bits/stdc++.h>
using namespace std;

#define sz(v) (int)v.size()
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
const int MAXN = 2e5+10, MAXM = 2e5+10, MAXL = 20, ALP = 26, INF = 1e9+10, MOD = 1e9+7, MAXK = 810;
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
// const ll INF = 1e18+10;

void solve(){
    ll x1, y1, z1, x2, y2, z2; cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
    ll ans = 2*min(z1, y2), lft1 = x1+min(z1, y2)+z2, lft2 = x2+y2-min(z1, y2);
    // cout << "MATCHED: " << min(z1, y2) << " LFT2 " << lft2 << "\n";
    y1 = max(0ll, y1-lft2); ans -= 2*y1;
    cout << ans << "\n";
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    cin >> t; 
    while (t--) solve();
}