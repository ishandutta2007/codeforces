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
const int MAXN = 1e2+10, MAXM = 40, MAXL = 20, ALP = 20, MOD = 1e9+7, MAXK = 17, INF = 1e9+10, MAXA = 1e2+10, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

void solve(){
    int n; cin >> n;
    vector<ll> a(n); for (auto& it : a) cin >> it;
    
    ll cnt[61]={};
    for (auto& it : a) for (int i = 0; i < 61; i++) if (it&(1ll<<i)) cnt[i]++;

    ll ans=0;
    for (int i = 0; i < n; i++){
        ll x=0, y=0;
        for (int j = 0; j < 61; j++) {
            ll c=(a[i]&(1ll<<j)?n:cnt[j]), v = c*((1ll<<j)%MOD)%MOD;
            x = (x+v)%MOD;
        }
        for (int j = 0; j < 61; j++) {
            ll c=(a[i]&(1ll<<j)?cnt[j]:0), v = c*((1ll<<j)%MOD)%MOD;
            y = (y+v)%MOD;
        }
        ans = (ans+x*y%MOD)%MOD;
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    cin >> t;
    while (t--) solve();
}