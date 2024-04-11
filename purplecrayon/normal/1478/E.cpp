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
const int MAXN = 2e5+10, MAXM = 40, MAXL = 20, ALP = 20, MOD = 1e9+7, MAXK = 17, INF = 1e9+10, MAXA = 1e2+10, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

struct SegTree {
    int n, t[4*MAXN], lzy[4*MAXN];
    
    void init(int _n) { n=_n; fill(t, t+4*n, 0), fill(lzy, lzy+4*n, -1); }

    void push(int v, int tl, int tr, int val){
        if (val==-1) return;
        t[v]=val*(tr-tl+1);
        if (tl != tr) lzy[2*v] = val, lzy[2*v+1] = val;
    }
    void upd(int v, int tl, int tr, int l, int r, int val){
        push(v, tl, tr, lzy[v]), lzy[v]=-1;
        if (r < tl || l > tr) return;
        if (l <= tl && tr <= r){ push(v, tl, tr, val); return; }
        int tm=(tl+tr)/2;
        upd(2*v, tl, tm, l, r, val), upd(2*v+1, tm+1, tr, l, r, val);

        t[v]=t[2*v]+t[2*v+1];
    }
    void upd(int l, int r, int val){ upd(1, 0, n-1, l, r, val); }
    int qry(int v, int tl, int tr, int l, int r){
        push(v, tl, tr, lzy[v]), lzy[v]=-1;
        if (r < tl || l > tr) return 0;
        if (l <= tl && tr <= r) return t[v];
        int tm=(tl+tr)/2;
        return qry(2*v, tl, tm, l, r)+qry(2*v+1, tm+1, tr, l, r);
    }
    int qry(int l, int r){ return qry(1, 0, n-1, l, r); }
} st;

void solve(){
    int n, q; cin >> n >> q;
    string s, t; cin >> s >> t;

    st.init(n);
    for (int i = 0; i < n; i++) st.upd(i, i, t[i]-'0');

    vector<ar<int, 2>> qt(q);
    for (auto& it : qt) cin >> it[0] >> it[1], --it[0], --it[1];

    for (int i = q-1; i >= 0; i--){
        int l=qt[i][0], r=qt[i][1];
        int cnt=st.qry(l, r), tot=r-l+1;
        if (cnt*2 == tot) { cout << no; return; }
        else if (cnt*2 < tot) st.upd(l, r, 0);
        else if (cnt*2 > tot) st.upd(l, r, 1);
        else assert(false);
    }
    for (int i = 0; i < n; i++) if (st.qry(i, i) != s[i]-'0') { cout << no; return; }
    cout << yes;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t_c=1;
    cin >> t_c;
    while (t_c--) solve();
}