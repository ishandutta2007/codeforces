#include <bits/stdc++.h>
using namespace std;

#define sz(v) (int)v.size()

typedef vector<int> vi;
typedef long long ll;
const int MAXN = 3e5+10, MAXM = 3e5+10, MAXL = 21, LEN = 320;
const string yes = "YES\n", no = "NO\n";

const ll is_query = -(1LL<<62);
struct Line {
    ll m, b;
    int idx;
    mutable function<const Line*()> succ;
    bool operator<(const Line& rhs) const {
        if (rhs.b != is_query) return m < rhs.m;
        const Line* s = succ();
        if (!s) return 0;
        ll x = rhs.m;
        return b - s->b < (s->m - m) * x;
    }
};
struct HullDynamic : public multiset<Line> { // will maintain upper hull for maximum
    bool bad(iterator y) {
        auto z = next(y);
        if (y == begin()) {
            if (z == end()) return 0;
            return y->m == z->m && y->b <= z->b;
        }
        auto x = prev(y);
        if (z == end()) return y->m == x->m && y->b <= x->b;
        return (x->b - y->b)*(z->m - y->m) >= (y->b - z->b)*(y->m - x->m);
    }
    void insert_line(Line l) {
        auto y = insert(l);
        if (bad(y)) { erase(y); return; }
        while (next(y) != end() && bad(next(y))) erase(next(y));
        y->succ = [=] { return next(y) == end() ? 0 : &*next(y); };
        while (y != begin() && bad(prev(y))) erase(prev(y));
        if(y != begin()) prev(y)->succ = [=] { return &*y; };
    }
    pair<ll, int> eval(ll x) {
        auto l = *lower_bound((Line) { x, is_query, -1 });
        return {l.m * x + l.b, l.idx};
    }
} hull[4*MAXN];

int n, q;
ll a[MAXN], b[MAXN];

void bld(int v, int tl, int tr){
    for (int i = tl; i <= tr; i++) hull[v].insert_line({b[i], a[i], i});
    if (tl != tr) {
        int tm = (tl+tr)>>1;
        bld(2*v, tl, tm); bld(2*v+1, tm+1, tr);
    }
}
pair<ll, int> qry(int v, int tl, int tr, int l, int r, ll x){
    if (l > tr || r < tl) return {-1e18, -1};
    if (l <= tl && tr <= r)
        return hull[v].eval(x);
    int tm = (tl+tr)>>1;
    return max(qry(2*v, tl, tm, l, r, x), qry(2*v+1, tm+1, tr, l, r, x));
}
void solve(){
    cin >> n >> q;
    for (int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
    }
    bld(1, 0, n-1);
    while (q--){
        int l, r; ll x; cin >> l >> r >> x, --l, --r;
        cout << qry(1, 0, n-1, l, r, x).second+1 << "\n";
    }
}
int main(){
    ios::sync_with_stdio(false); cin.sync_with_stdio(false); cin.tie(0);
    int t=1;
    // cin >> t;
    while (t--) solve();
}