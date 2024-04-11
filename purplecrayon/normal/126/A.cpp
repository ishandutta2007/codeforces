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
const int MAXN = 5e3+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 17, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
 
void solve(){
    ll t1, t2, x1, x2, t0; cin >> t1 >> t2 >> x1 >> x2 >> t0;

    if (t0==t1){
        if (t0^t2) cout << x1 << ' ' << 0 << '\n';
        else cout << x1 << ' ' << x2 << '\n';
        return;
    }

    ll anm=1e9, adm=1;
    pair<ll, ll> ans{-1, -1};
    for (ll i = 1; i <= x2; i++){
        ll c=min((i*(t2-t0))/(t0-t1), x1);
        ll cnm = t1*c + t2*i - t0*c - t0*i, cdm = i+c;
        if (cnm*adm <= anm*cdm){
            anm=cnm, adm=cdm;
            ans=make_pair(c, i);
        }
    }
    cout << ans.first << ' ' << ans.second << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t_c=1;
    //cin >> t_c;
    while (t_c--) solve();
}