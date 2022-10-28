#include "bits/stdc++.h"
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e3+10, MOD = 1e9+7;

void solve(){
    ll x, y, a, b; cin >> x >> y >> a >> b;
    if (x > y) swap(x, y);
    if (a > b) swap(a, b);

    ll d = b-a, c = y-x;
    ll v = min({(d ? c/d : x/a), x/a, y/b}); //how many static

    x -= v*a, y -= v*b;
    ll ans = v;


    v = min(x/(a+b), y/(a+b));

    x -= v*(a+b), y -= v*(a+b);
    ans += v*2;


    if (x > y) swap(x, y);
    if (x >= a && y >= b) {
        ans++;
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}