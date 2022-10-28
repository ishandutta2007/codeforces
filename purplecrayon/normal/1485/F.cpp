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
const int MAXN = 3e3+10, MAXM = 5e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 110, MAXA = 1e2+10, MAXB = 24, MAXBB = (1<<MAXB), MOD2=MOD-1;
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

void solve_slow(){
    //find # subseq of n s.t. for any two adj elements in the subseq (i, j) ps[i-1]-ps[j] != b[j]
    //ps[i-1]-b[i] == ps[j]-b[j]
    int n; cin >> n;
    vector<ll> b(n); for (auto& it : b) cin >> it;
    vector<ll> ps(n);
    for (int i = 0; i < n; i++) ps[i] = b[i]+(i?ps[i-1]:0);

    int ans=0;
    set<vector<ll>> s;
    for (int i = 0; i < (1<<n); i++){
        int p=-1; bool bad=0;
        vector<ll> a(n);
        for (int j = 0; j < n; j++){
            if ((i>>j)&1^1) a[j] = b[j];
            else {
                ll sm=0;
                for (int k = j-1; k >= 0; k--) sm += a[k];
                a[j] = b[j]-sm;
            }
        }
        for (int j = 0; j < n && !bad; j++) if ((i>>j)&1){
            if (p == -1){
                bad = b[j]-(j?ps[j-1]:0ll) == b[j];
            } else {
                bad = b[j] == b[j]-(ps[j-1]-ps[p]+b[p]);
            }
            p = j;
        }
        for (int j = 0; j < n; j++) if ((i>>j)&1){
            if (a[j] == b[j]) assert(bad);
        }
        s.insert(a);
        ans += !bad;
    }
    cout << sz(s) << '\n';
}
void solve(){
    //find # subseq of n s.t. for any two adj elements in the subseq (i, j) ps[i-1]-ps[j] != b[j]
    //ps[i-1]-b[i] == ps[j]-b[j]
    int n; cin >> n;
    vector<ll> b(n); for (auto& it : b) cin >> it;
    vector<ll> ps(n);
    for (int i = 0; i < n; i++) ps[i] = b[i]+(i?ps[i-1]:0);

    /*
    int ans=0;
    for (int i = 0; i < (1<<n); i++){
        int p=-1; bool bad=0;
        for (int j = 0; j < n && !bad; j++) if ((i>>j)&1){
            if (p == -1){
                bad = b[j]-(j?ps[j-1]:0ll) == b[j];
            } else {
                bad = b[j] == b[j]-(ps[j-1]-ps[p]+b[p]);
            }
            p = j;
        }
        ans += !bad;
    }
    cout << ans << '\n';
    */
    //ps[j-1] != ps[p]-b[p];

    map<ll, ll> dp;
    dp[0] = 1;
    ll sm=1;
    for (int i = 0; i < n; i++){
        ll p = (i?ps[i-1]:0ll);
        ll cdp = (sm-dp[p]+MOD)%MOD;
        sm = (sm+cdp)%MOD, dp[ps[i]-b[i]] = (dp[ps[i]-b[i]]+cdp)%MOD;
    }
    cout << sm << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t_c=1;
    cin >> t_c;
    while (t_c--) {
        solve();
    }
}