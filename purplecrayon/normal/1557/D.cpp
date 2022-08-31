#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 3e5+10, MOD = 1e9+7;

int n, m, t[8*MAXN], lzy[8*MAXN], dp[MAXN], nxt[MAXN];
vector<ar<int, 2>> seg[MAXN];
map<int, int> comp;

int mx(int a, int b) {
    if (min(a, b) == -1) return max(a, b);
    return dp[a] > dp[b] ? a : b;
}

void push(int v, int tl, int tr, int x) {
    if (x == -1) return;
    t[v] = mx(t[v], x);
    if (tl != tr) {
        lzy[2*v] = mx(lzy[2*v], x);
        lzy[2*v+1] = mx(lzy[2*v+1], x);
    }
}
void upd(int v, int tl, int tr, int l, int r, int x) {
    push(v, tl, tr, lzy[v]), lzy[v] = -1;
    if (r < tl || l > tr) return;
    if (l <= tl && tr <= r) {
        push(v, tl, tr, x);
        return;
    }
    int tm=(tl+tr)/2;
    upd(2*v, tl, tm, l, r, x), upd(2*v+1, tm+1, tr, l, r, x);
    t[v] = mx(t[2*v], t[2*v+1]);
}
void upd(int l, int r, int x) {
    upd(1, 0, 2*m-1, l, r, x);
    //for (int i = l; i <= r; i++) t[i] = mx(t[i], x);
}
int qry(int v, int tl, int tr, int l, int r) {
    push(v, tl, tr, lzy[v]), lzy[v] = -1;
    if (r < tl || l > tr) return -1;
    if (l <= tl && tr <= r) return t[v];
    int tm=(tl+tr)/2;
    return mx(qry(2*v, tl, tm, l, r), qry(2*v+1, tm+1, tr, l, r));
}
int qry(int l, int r) {
    return qry(1, 0, 2*m-1, l, r);
    /*
    int ans = -1;
    for (int i = l; i <= r; i++) ans = mx(ans, t[i]);
    return ans;
    */
}
void solve(){
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int row, l, r; cin >> row >> l >> r, --row, --l, --r;
        seg[row].push_back({l, r});

        comp[l]++, comp[r]++;
    }
    int cc = 0;
    for (auto& c : comp) c.second = cc++;

    memset(t, -1, sizeof(t)), memset(lzy, -1, sizeof(lzy));

    //get_max{l, r} -> get index
    //set_max{l, r} ->

    int st = -1;
    for (int i = n-1; i >= 0; i--) {
        nxt[i] = -1;
        for (auto [l, r] : seg[i]) {
            nxt[i] = mx(nxt[i], qry(comp[l], comp[r]));
        }
        dp[i] = (nxt[i] == -1 ? 0 : dp[nxt[i]])+1;
        st = mx(st, i);
        for (auto [l, r] : seg[i]) {
            upd(comp[l], comp[r], i);
        }
    }
    vector<bool> keep(n);
    int c = st;
    while (c != -1) {
        keep[c] = 1;
        c = nxt[c];
    }

    int ans = n-dp[st];
    cout << ans << '\n';

    int me = 0;
    for (int i = 0; i < n; i++) if (!keep[i]) {
        cout << i+1 << ' ';
        me++;
    }
    assert(me == ans);
    cout << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}