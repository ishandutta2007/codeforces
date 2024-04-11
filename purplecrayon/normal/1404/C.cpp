#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 3e5+10, MOD = 998244353;


int n, q, a[MAXN], ans[MAXN];
vector<ar<int, 2>> qr[MAXN];

int t[4*MAXN], lzy[4*MAXN];
void push(int v, int tl, int tr, int x) {
    t[v] += x;
    if (tl != tr) {
        lzy[2*v] += x;
        lzy[2*v+1] += x;
    }
}
void app(int v, int tl, int tr) {
    push(v, tl, tr, lzy[v]), lzy[v] = 0;
}
void upd(int v, int tl, int tr, int l, int r, int x) {
    app(v, tl, tr);
    if (r < tl || l > tr) return;
    if (l <= tl && tr <= r) {
        push(v, tl, tr, x);
        return;
    }
    int tm=(tl+tr)/2;
    upd(2*v, tl, tm, l, r, x), upd(2*v+1, tm+1, tr, l, r, x);
    t[v] = max(t[2*v], t[2*v+1]);
}
int qry(int v, int tl, int tr, int pos) {
    app(v, tl, tr);
    if (tl == tr) return t[v];
    int tm=(tl+tr)/2;
    if (pos <= tm) return qry(2*v, tl, tm, pos);
    else return qry(2*v+1, tm+1, tr, pos);
}
int qry_whole() {
    app(1, 0, n-1);
    return t[1];
}
int last_greater(int v, int tl, int tr, int x) { //find the last thing such that value is >= x
    if (tl == tr) return tl;
    int tm=(tl+tr)/2;
    app(v, tl, tr), app(2*v, tl, tm), app(2*v+1, tm+1, tr);
    if (t[2*v+1] >= x) return last_greater(2*v+1, tm+1, tr, x);
    return last_greater(2*v, tl, tm, x);
}

void solve(){
    cin >> n >> q;
    for (int i = 0; i < n; i++) cin >> a[i], --a[i], a[i] = i-a[i];

    for (int qt = 0; qt < q; qt++) {
        int x, y; cin >> x >> y, y = n-y-1;
        qr[y].push_back({x, qt});
    }

    for (int i = 0; i < n; i++) {
        if (a[i] >= 0 && qry_whole() >= a[i]) {
            int last = last_greater(1, 0, n-1, a[i]);
            upd(1, 0, n-1, 0, min(i, last), +1);
        }
        for (auto [l, qt] : qr[i]) {
            ans[qt] = qry(1, 0, n-1, l);
        }
    }
    for (int i = 0; i < q; i++) {
        cout << ans[i] << '\n';
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}