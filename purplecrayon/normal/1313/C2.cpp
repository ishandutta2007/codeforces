#include "bits/stdc++.h"
using namespace std;

#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
const int MAXN = 5e5+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 17, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

const ll NONE = 1e18+10;

struct SegTree {
    ll t[4*MAXN], lzy[4*MAXN];
    void init(int n){
        fill(lzy, lzy+4*n, NONE); fill(t, t+4*n, 0);
    }
    void push(int v, int tl, int tr){
        if (lzy[v] == NONE) return;
        t[v] = lzy[v]*(tr-tl+1);
        if (tl != tr) lzy[2*v] = lzy[v], lzy[2*v+1] = lzy[v];
        lzy[v] = NONE;
    }
    void app(int v, int tl, int tr, ll val){
        lzy[v] = val;
        push(v, tl, tr);
    }
    void upd(int v, int tl, int tr, int l, int r, ll val){
        push(v, tl, tr);
        if (r < l || r < tl || l > tr) return;
        if (l <= tl && tr <= r){
            app(v, tl, tr, val);
            return;
        }
        int tm=(tl+tr)/2;
        upd(2*v, tl, tm, l, r, val), upd(2*v+1, tm+1, tr, l, r, val);
        t[v] = t[2*v]+t[2*v+1];
    }
    ll qry(int v, int tl, int tr, int l, int r){
        push(v, tl, tr);
        if (r < l || r < tl || l > tr) return 0ll;
        if (l <= tl && tr <= r) return t[v];
        int tm=(tl+tr)/2;
        return qry(2*v, tl, tm, l, r)+qry(2*v+1, tm+1, tr, l, r);
    }
};
void pr(vector<ll> a){
    for (auto& it : a) cout << it << ' ';
    cout << '\n';
}
void solve(){
    int n; cin >> n; 
    vector<ll> a(n); for (auto& it : a) cin >> it;
    pair<ll, int> ans; ans = make_pair(-1, -1);
    {
        vector<ll> c(n);
        c[0] = a[0]; ll tot=c[0];
        for (int i = 1; i < n; i++) c[i] = min(a[i], c[i-1]), tot += c[i];
        ans = max(ans, make_pair(tot, 0));
    }
    {
        vector<ll> c(n);
        c[n-1] = a[n-1]; ll tot=c[n-1];
        for (int i = n-2; i >= 0; i--) c[i] = min(a[i], c[i+1]), tot += c[i];
        ans = max(ans, make_pair(tot, n-1));
    }
    vector<int> l(n, -1), r(n, n);
    {
        vector<int> st;
        for (int i = 0; i < n; i++){
            while (sz(st) && a[st.back()] > a[i]) st.pop_back();
            if (sz(st)) l[i] = st.back();
            st.push_back(i);
        }
        st.clear();
        for (int i = n-1; i >= 0; i--){
            while (sz(st) && a[st.back()] > a[i]) st.pop_back();
            if (sz(st)) r[i] = st.back();
            st.push_back(i);
        }
    }
    SegTree st; vector<ll> v(n);
    st.init(n); st.upd(1, 0, n-1, 0, 0, a[0]);
    for (int i = 1; i < n-1; i++){
        st.upd(1, 0, n-1, l[i]+1, i, a[i]);
        v[i] += st.qry(1, 0, n-1, 0, i);
    }
    st.init(n); st.upd(1, 0, n-1, n-1, n-1, a[n-1]);
    for (int i = n-2; i >= 1; i--){
        st.upd(1, 0, n-1, i, r[i]-1, a[i]);
        v[i] += st.qry(1, 0, n-1, i, n-1);
    }
    for (int i = 1; i < n-1; i++) v[i] -= a[i];
    //for (int i = 1; i < n-1; i++) cout << i << ' ' << v[i] << '\n';
    for (int i = 1; i < n-1; i++) ans = max(ans, make_pair(v[i], i));
    auto construct = [&](int m){
        vector<ll> c(n); c[m] = a[m];
        for (int i = m-1; i >= 0; i--) c[i] = min(a[i], c[i+1]);
        for (int i = m+1; i < n; i++) c[i] = min(a[i], c[i-1]);
        return c;
    };
    pr(construct(ans.second));
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    //cin >> t;
    while (t--) solve(); 
}