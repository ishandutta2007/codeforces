#include "bits/stdc++.h"
using namespace std;
 
template<class T> using min_pq=priority_queue<T, vector<T>, greater<T>>;
 
#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
const int MAXN = 2e2+10, MAXQ = 3e5+10, MAXL = 18, ALP = 26, MOD = 95542721, MAXK = 1e2+10,  MAXA = 10, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
const ll INF = 1e18+10;

ll v(ll x) {
        ll ans = 0, a = 1, b = 9, c = 9;
        for (; b < x; a++, b += c*10, c*=10) {
            ans += c*(c+1)/2 * a + a*c*(x-b);
        }
        return ans + a*(x-b/10)*(x-b/10+1)/2;
}
void solve(){
    ll x; cin >> x, --x;

    ll lo=-1, hi=1e9+10, mid=(lo+hi)/2;
    while (lo < mid && mid < hi) {
        if (v(mid) > x) hi=mid;
        else lo=mid;
        mid=(lo+hi)/2;
    }

    x -= v(lo);

    ll cnt = 9, tot = 1;
    for (; x >= cnt*tot; cnt*=10, tot++) x -= cnt*tot;
    ll val = cnt/9+x/tot;
    cout << to_string(val)[x%tot] << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t_c=1;
    cin >> t_c;
    while (t_c--) solve();
}