#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = (1 << 18) + 10, MOD = 1e9+7;

struct T {
    ll ans = 0;
    ll L = 0, R = 0;
    ll sum = 0;

    T() { }
    T(ll x) {
        sum = x;
        ans = L = R = max(x, 0LL);
    }
};

T comb(const T& a, const T& b) {
    T ans; ans.sum = a.sum + b.sum;
    ans.L = max(a.L, a.sum + b.L);
    ans.R = max(b.R, b.sum + a.R);
    ans.ans = max({a.ans, b.ans, a.R + b.L});
    return ans;
}

int n, a[N];
ll ans[N];

struct Tree {
    T val;
    Tree *l = nullptr, *r = nullptr;
    int tl, tr;
 
    Tree(int _tl, int _tr): tl(_tl), tr(_tr) {}

    void build() {
        if (tl == tr) val = T(a[tl]);
        else {
            int tm = (tl + tr) / 2;
            l = new Tree(tl, tm), r = new Tree(tm+1, tr);
            l->build(), r->build();
            val = comb(l->val, r->val);
        }
    }

    ll get() { 
        return val.ans;
    }
    void upd(int level) {
        if (tr - tl + 1 == level) swap(l, r);
        else l->upd(level), r->upd(level);
        val = comb(l->val, r->val);
    }
} *t;

void rec(int c, int x) {
    if (c == n) {
        ans[x] = t->get();
        return;
    }
    rec(c + 1, x);
    t->upd(1 << (c + 1));
    rec(c + 1, x ^ (1 << c));
    t->upd(1 << (c + 1));
}
void solve() {
    cin >> n;
    for (int i = 0; i < (1 << n); i++) cin >> a[i];
    t = new Tree(0, (1 << n) - 1); t->build();
    rec(0, 0);

    int q; cin >> q;

    int cur = 0;
    while (q--) {
        int k; cin >> k;
        cur ^= 1 << k;
        cout << ans[cur] << '\n';
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}