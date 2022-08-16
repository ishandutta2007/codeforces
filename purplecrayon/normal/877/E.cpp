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
const int MAXN = 2e5+10, MAXQ = 3e5+10, MAXL = 18, ALP = 26, MOD = 1e9+7, MAXK = 17,  MAXA = 10, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
const ll INF = 1e18+10;

int n, a[MAXN], b[MAXN], st[MAXN], en[MAXN], et[MAXN], tt=0;
vector<int> adj[MAXN];
int t[4*MAXN];
bool lzy[4*MAXN];

void dfs(int c=0, int p=-1) {
    et[st[c]=tt++] = c;
    for (auto nxt : adj[c]) dfs(nxt, c);
    en[c]=tt-1;
}
void push(int v, int tl, int tr, bool val) {
    if (!val) return;
    t[v] = (tr-tl+1)-t[v];
    if (tl != tr) lzy[2*v] ^= val, lzy[2*v+1] ^= val;
}
void upd(int v, int tl, int tr, int l, int r, bool val) {
    push(v, tl, tr, lzy[v]), lzy[v] = 0;
    if (r < tl || l > tr) return;
    if (l <= tl && tr <= r){ push(v, tl, tr, val); return; }
    int tm=(tl+tr)/2;
    upd(2*v, tl, tm, l, r, val), upd(2*v+1, tm+1, tr, l, r, val);
    t[v] = t[2*v]+t[2*v+1];
}
int qry(int v, int tl, int tr, int l, int r) {
    push(v, tl, tr, lzy[v]), lzy[v] = 0;
    if (r < tl || l > tr) return 0;
    if (l <= tl && tr <= r) return t[v];
    int tm=(tl+tr)/2;
    return qry(2*v, tl, tm, l, r) + qry(2*v+1, tm+1, tr, l, r);
}
void solve(){
    cin >> n;
    for (int i = 1; i < n; i++) {
        int p; cin >> p, --p;
        adj[p].push_back(i);
    }
    for (int i = 0; i < n; i++) cin >> a[i];
    dfs();
    for (int i = 0; i < n; i++) b[i] = a[st[i]];

    memset(t, 0, sizeof(t)), memset(lzy, 0, sizeof(lzy));
    for (int i = 0; i < n; i++) upd(1, 0, n-1, i, i, a[et[i]]);
    int q; cin >> q;
    while (q--) {
        string s; cin >> s;
        int c; cin >> c, --c;
        if (s[0] == 'g') {
            cout << qry(1, 0, n-1, st[c], en[c]) << '\n';
        } else {
            upd(1, 0, n-1, st[c], en[c], 1);
        }
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t_c=1;
    //cin >> t_c;
    while (t_c--) solve();
}