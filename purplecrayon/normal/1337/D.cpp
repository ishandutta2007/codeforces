#include <bits/stdc++.h>
using namespace std;

#define sz(v) (int)v.size()
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
const int MAXN = 2e5+10, MAXM = 2e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 810;
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
const ll INF = 9e18+10;

ll ans;

ll sq(ll x){
    return x*x;
}
void getAns(const vector<ll>& a, const vector<ll>& b, const vector<ll>& c){
    for (auto x1 : a){
        auto i1 = lower_bound(b.begin(), b.end(), x1);
        auto i2 = upper_bound(c.begin(), c.end(), x1);
        if (i1 != b.end() && i2 != c.begin()){
            --i2;
            ll x2 = *i1, x3 = *i2;
            ans = min(ans, sq(x1-x2)+sq(x2-x3)+sq(x1-x3));
        }
    }
}
void solve(){
    int an, bn, cn; cin >> an >> bn >> cn;
    vector<ll> a(an), b(bn), c(cn);
    for (auto& it : a) cin >> it;
    for (auto& it : b) cin >> it;
    for (auto& it : c) cin >> it;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    ans = INF;
    getAns(a, b, c); getAns(a, c, b);
    getAns(b, a, c); getAns(b, c, a);
    getAns(c, a, b); getAns(c, b, a);
    cout << ans << "\n";
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    cin >> t; 
    while (t--) solve();
}