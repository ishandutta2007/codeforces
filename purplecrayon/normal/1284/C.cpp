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
const int MAXN = 2e5+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 17, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

void solve(){
    int n; ll m; cin >> n >> m;
    vector<ll> fact(n+1, 1);
    for (int i = 1; i <= n; i++) fact[i] = i*fact[i-1]%m;
    ll ans=0;
    for (int i = 1; i <= n; i++){
        ll nm_rng = n-i+1, nm_loc = n-i+1, nm_ch = i, nm_op = n-nm_ch;
        ll c = nm_rng*nm_loc%m*fact[nm_ch]%m*fact[nm_op]%m;
        ans = (ans+c)%m;
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t_c=1;
    //cin >> t_c;
    while (t_c--) solve();
}