#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = (1<<19)+10, MOD = 1e9+7;

struct T {
    int z_left = 0, z_right = 0, ans = 0;
    int len;
};

int n, k, ans[MAXN];
bool a[MAXN];

T make_empty(int v) {
    T res;

    if (v) res.z_left = 0, res.z_right = 0;
    else res.z_left = MOD, res.z_right = MOD;

    res.len = 1, res.ans = MOD;
    return res;
}
T comb(T l, T r) {
    T res;
    res.z_left = min(l.z_left, l.len+r.z_left);
    res.z_right = min(r.z_right, r.len+l.z_right);
    res.len = l.len + r.len;

    res.ans = min({l.ans, r.ans, l.z_right+r.z_left+1});
    return res;
}

struct Tree {
    T val;
    Tree *l = nullptr, *r = nullptr;
    int tl, tr;

    Tree(int _tl, int _tr): tl(_tl), tr(_tr) {}
    void bld() {
        if (tl == tr) val = make_empty(a[tl]);
        else {
            int tm=(tl+tr)/2;
            l = new Tree(tl, tm), r = new Tree(tm+1, tr);
            l->bld(), r->bld();
            val = comb(l->val, r->val);
        }
    }
    int get(){ return val.ans; }
    void upd(int level) {
        if (tr-tl+1 == level) swap(l, r);
        else l->upd(level), r->upd(level);
        val = comb(l->val, r->val);
    }
} *t;

void rec(int c, int x) {
    if (c == k) {
        ans[x] = t->get();
        return;
    }
    rec(c+1, x);
    t->upd(1<<(c+1));
    rec(c+1, x^(1<<c));
    t->upd(1<<(c+1));
}
void solve(){
    cin >> n >> k;
    while (n--){ int c; cin >> c; a[c] = 1; }

    t = new Tree(0, (1<<k)-1), t->bld();
    rec(0, 0);
    for (int i = 0; i < (1<<k); i++) cout << ans[i] << ' '; cout << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}