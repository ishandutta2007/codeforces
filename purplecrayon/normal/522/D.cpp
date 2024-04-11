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
const int MAXN = 5e5+10, MAXM = 40, MAXL = 20, ALP = 20, MOD = 1e9+7, MAXK = 17, INF = 1e9+10, MAXA = 1e2+10, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

int n, m, a[MAXN], nxt[MAXN], ans[MAXN];
map<int, int> mp;
ar<int, 3> qs[MAXN];
vector<ar<int, 2>> ql[MAXN];

int t[4*MAXN];
void upd(int v, int tl, int tr, int pos, int val) {
    if (pos < tl || pos > tr) return;
    if (tl == tr) { t[v] = min(t[v], val); return; }
    int tm=(tl+tr)/2;
    upd(2*v, tl, tm, pos, val), upd(2*v+1, tm+1, tr, pos, val);
    t[v] = min(t[2*v], t[2*v+1]);
}
int qry(int v, int tl, int tr, int l, int r) {
    if (r < tl || l > tr) return INF;
    if (l <= tl && tr <= r) return t[v];
    int tm=(tl+tr)/2;
    return min(qry(2*v, tl, tm, l, r), qry(2*v+1, tm+1, tr, l, r));
}
void upd(int pos, int val) { upd(1, 0, n-1, pos, val); }
//void upd(int pos, int val){ t[pos] = min(t[pos], val); }
//int qry(int l, int r){ int ans=INF; for (int i = l; i <= r; i++) ans=min(ans, t[i]); return ans; }
int qry(int l, int r){ return qry(1, 0, n-1, l, r); }

void solve(){
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i], mp[a[i]]++;
    int cc=0; for (auto& it : mp) it.second = cc++;
    for (int i = 0; i < n; i++) a[i] = mp[a[i]];

    for (int i = 0; i < m; i++) {
        cin >> qs[i][0] >> qs[i][1], --qs[i][0], --qs[i][1]; qs[i][2] = i;
        ql[qs[i][0]].push_back({qs[i][1], i});
    }
    fill(t, t+4*n, INF);
    memset(nxt, -1, sizeof(nxt));
    for (int i = n-1; i >= 0; i--) {
        if (nxt[a[i]] != -1) {
            upd(nxt[a[i]], nxt[a[i]]-i);
        }
        nxt[a[i]] = i;
        for (auto it : ql[i]) ans[it[1]] = qry(i, it[0]);
    }
    for (int i = 0; i < m; i++) cout << (ans[i]==INF?-1:ans[i]) << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t_c=1;
    //cin >> t_c;
    while (t_c--) solve();
}