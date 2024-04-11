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
const int MAXN = 3e5+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 998244353, MAXK = 17, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
const ll INF = 1e18+10;
 
int n;
ll t[4*MAXN];

void upd(int v, int tl, int tr, int pos, ll nv){
    if (pos < tl || pos > tr) return;
    if (tl == tr){ t[v] = nv; return; }
    int tm=(tl+tr)/2;
    upd(2*v, tl, tm, pos, nv), upd(2*v+1, tm+1, tr, pos, nv);
    t[v] = max(t[2*v], t[2*v+1]);
}
void upd(int pos, ll nv){ upd(1, 0, n-1, pos, nv); }
ll qry(int v, int tl, int tr, int l, int r){
    if (r < tl || l > tr) return -INF;
    if (l <= tl && tr <= r) return t[v];
    int tm=(tl+tr)/2;
    return max(qry(2*v, tl, tm, l, r), qry(2*v+1, tm+1, tr, l, r));
}
ll qry(int l, int r){ return qry(1, 0, n-1, l, r); }
void solve(){
    cin >> n;
    vector<int> a(n); for (auto& it : a) cin >> it;
    vector<ll> b(n); for (auto& it : b) cin >> it;

    vector<int> st;
    vector<ll> dp(n, -INF);


    memset(t, 0, sizeof(t));

    for (int i = 0; i < n; i++) {
        while (sz(st) && a[st.back()] >= a[i]) st.pop_back();
        if (sz(st)) {
            dp[i] = max(dp[i], dp[st.back()]);
            dp[i] = max(dp[i], b[i]+qry(st.back(), i-1));
        } else {
            dp[i] = b[i]+max(0ll, qry(0, i-1));
        }
        upd(i, dp[i]);
        st.push_back(i);
    }
    cout << dp[n-1] << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t_c=1;
    //cin >> t_c;
    while (t_c--) solve();
}