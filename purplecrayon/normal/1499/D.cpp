#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;


//lcm = prod/gcd
//
//c*prod/gcd - d*gcd = x
//
//iterate over factors of x as the gcd (since lhs is a multiple of gcd)
//c*prod/gcd = value (x + d*gcd)
//prod = (x+d*gcd)*gcd/c
//

const int MAXV = 3e7+10;
int distinct[MAXV];
bool comp[MAXV];

void pre() {
    memset(comp, 0, sizeof(comp));
    for (int i = 2; i < MAXV; i++) if (!comp[i]) {
        distinct[i]++;
        for (int j = 2*i; j < MAXV; j+=i) distinct[j]++, comp[j] = 1;
    }
    
}
void solve(){
    ll c, d, x; cin >> c >> d >> x;

    ll ans = 0;
    auto get = [&](int g) {
        ll prod = x/g+d;
        if (prod%c) return;
        prod /= c;

        //we know the excess stuff
        ans += 1ll<<distinct[prod];
    };

    for (int i = 1; i*i <= x; i++) if (x%i == 0) {
        get(i);
        if (i*i != x) get(x/i);
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    pre();
    cin >> T;
    while (T--) solve();
}