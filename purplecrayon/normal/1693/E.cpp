#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 1e9+7;

// 0 -> must use left
// 1 -> must use right
// 2 -> can use either
// 3 -> inactive
// 4 -> temporarily inactive

const int M = 5;


int n, a[N];
vector<int> loc[N];

struct T {
    int nxt[M], cnt[M];
    void comb(const T& l, const T& r) {
        std::iota(nxt, nxt + M, 0);
        for (int i = 0; i < M; i++) cnt[i] = l.cnt[i] + r.cnt[i];
    }
} t[4*N];

int store_nxt[M], store_cnt[M];
void push(int v, int tl, int tr) {
    if (tl < tr) {
        for (int i = 0; i < M; i++) store_nxt[i] = t[v].nxt[t[2*v].nxt[i]];
        memcpy(t[2*v].nxt, store_nxt, sizeof(store_nxt));
        
        for (int i = 0; i < M; i++) store_nxt[i] = t[v].nxt[t[2*v+1].nxt[i]];
        memcpy(t[2*v+1].nxt, store_nxt, sizeof(store_nxt));
    }
    memset(store_cnt, 0, sizeof(store_cnt));
    for (int i = 0; i < M; i++) store_cnt[t[v].nxt[i]] += t[v].cnt[i];
    memcpy(t[v].cnt, store_cnt, sizeof(store_cnt));
    std::iota(t[v].nxt, t[v].nxt + M, 0);
}
void build(int v, int tl, int tr) {
    if (tl == tr) {
        std::iota(t[v].nxt, t[v].nxt + M, 0);
        memset(t[v].cnt, 0, sizeof(t[v].cnt));
        t[v].cnt[3]++;
    } else {
        int tm = (tl + tr) / 2;
        build(2*v, tl, tm), build(2*v+1, tm+1, tr);
        t[v].comb(t[2*v], t[2*v+1]);
    }
}
void upd(int v, int tl, int tr, int l, int r, int a, int b) {
    push(v, tl, tr);
    if (r < tl || l > tr) return;
    if (l <= tl && tr <= r) {
        t[v].nxt[a] = b;
        push(v, tl, tr);
        return;
    }
    int tm = (tl + tr) / 2;
    upd(2*v, tl, tm, l, r, a, b), upd(2*v+1, tm+1, tr, l, r, a, b);
    t[v].comb(t[2*v], t[2*v+1]);
}
void upd(int l, int r, int a, int b) {
    upd(1, 0, n-1, l, r, a, b);
}
int qry(int v, int tl, int tr, int l, int r, int x) {
    push(v, tl, tr);
    if (r < tl || l > tr) return 0;
    if (l <= tl && tr <= r) return t[v].cnt[x];
    int tm = (tl + tr) / 2;
    return qry(2*v, tl, tm, l, r, x) + qry(2*v+1, tm+1, tr, l, r, x);
}
int qry(int l, int r, int x) {
    return qry(1, 0, n-1, l, r, x);
}
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    n += 2;
    for (int i = 0; i < n; i++) loc[a[i]].push_back(i);

    build(1, 0, n-1);

    ll ans = 0;
    for (int i = n; i >= 0; i--) {
        for (int x : loc[i]) {
            ans += qry(0, x-1, 1) + qry(x+1, n-1, 0);
            upd(0, x-1, 2, 0), upd(x+1, n-1, 2, 1);
            upd(0, x-1, 1, 4), upd(x+1, n-1, 0, 4);
        }
        for (int x : loc[i]) { // change it from inactive to can use either
            upd(x, x, 3, 2);
        }
        upd(0, n-1, 4, 2);
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}