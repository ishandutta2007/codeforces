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
const int MAXN = 5e5+10, MAXQ = 5e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 17, MAXA = 62, MAXB = 24, MAXBB = (1<<MAXB), MOD2=MOD-1;
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
const ll INF = 1e18+10;

struct SegTree {
    pair<int, int> t[4*MAXN];
    void init(int n){
        fill(t, t+4*n, make_pair(-1, -1));
    }
    void upd(int v, int tl, int tr, int pos, int val){
        if (pos < tl || pos > tr) return;
        if (tl == tr) {
            t[v] = {val, pos};
            return;
        }
        int tm=(tl+tr)/2;
        upd(2*v, tl, tm, pos, val), upd(2*v+1, tm+1, tr, pos, val);
        t[v] = max(t[2*v], t[2*v+1]);
    }
    pair<int, int> qry(int v, int tl, int tr, int l, int r){
        if (r < tl || l > tr) return make_pair(-1, -1);
        if (l <= tl && tr <= r) return t[v];
        int tm=(tl+tr)/2;
        return max(qry(2*v, tl, tm, l, r), qry(2*v+1, tm+1, tr, l, r));
    }
    void _pr(int v, int tl, int tr){
        if (tl == tr){
            cerr << t[v].first << ' ';
        } else {
            int tm=(tl+tr)/2;
            _pr(2*v, tl, tm), _pr(2*v+1, tm+1, tr);
        }
    }
    void pr(int n){
        cerr << "ST: "; _pr(1, 0, n-1); cerr << '\n';
    }
} st;

int n, q, a[MAXN], nxt[MAXN], ans[MAXQ];
vector<int> loc[MAXN];
vector<pair<int, int>> ql[MAXN];

void solve(){
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i], loc[a[i]].push_back(i);
    cin >> q;
    for (int qt=0; qt < q; qt++){
        int l, r; cin >> l >> r, --l, --r;
        ql[l].emplace_back(r, qt); ans[qt]=0;
    }
    fill(nxt, nxt+n, n);
    for (int i = 1; i <= 5e5; i++) if (sz(loc[i])) {
        for (int j = 0; j < sz(loc[i])-1; j++) nxt[loc[i][j]] = loc[i][j+1];
    }
    //for (int i = 0; i < n; i++) cerr << nxt[i] << ' '; cerr << '\n';
    st.init(n);
    for (int l = n-1; l >= 0; l--){
        if (nxt[l] < n) {
            //erase nxt[l]
            st.upd(1, 0, n-1, nxt[l], -1);
        }
        //add l
        st.upd(1, 0, n-1, l, nxt[l]);
        //st.pr(n);
        //for everything in my range, find the max of nxt[i]
        for (auto& it : ql[l]){
            int r=it.first, qt=it.second;
            auto c = st.qry(1, 0, n-1, l, r);
            //if (l == 1) cout << c.first << ' ' << c.second << '\n', st.pr(n);
            if (c.first > r) ans[qt] = a[c.second];
        }
    } 
    for (int i = 0; i < q; i++) cout << ans[i] << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    //cin >> t;
    while (t--) solve();
}