#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;


bool done() {
    int p; cin >> p;
    assert(p == 0);
    exit(0);
}
void get(ar<ll, 3> x) {
    ll y = 3*max({x[0], x[1], x[2]})-(x[0]+x[1]+x[2]);
    //2*c-(a+b)
    cout << y << endl;

    int p; cin >> p, --p;
    if (x[p] <= x[(p+1)%3] && x[p] <= x[(p+2)%3]) {
        //2*c-b, b, c,
        ll c = max(x[(p+1)%3], x[(p+2)%3]);
        ll b = min(x[(p+1)%3], x[(p+2)%3]);
        cout << c-b << endl;

        done();
    } else if (x[p] >= x[(p+1)%3] && x[p] >= x[(p+2)%3]) {
        //c is forbidden, proceed as before
        x[p] += y;
        get(x);

        assert(false);
    } else {
        //a, c, 2*c-a


        ll c = max(x[(p+1)%3], x[(p+2)%3]);
        ll a = min(x[(p+1)%3], x[(p+2)%3]);
        cout << c-a << endl;

        done();
    }
}
void solve(){
    ar<ll, 3> x; for (auto& v : x) cin >> v;
    cout << "First" << endl;
    get(x);
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}